#include "game.h"
#include "basic_entity_factory.h"

//temporary
#include "fixed_vector.h"

Game::Game() :
  myGL(),
  input(Input(myGL)),
  graphics(Graphics(myGL)),
  entitySystem()
{
  BasicEntityFactory *bef = new BasicEntityFactory();
  entitySystem.produceEntityFromFactory(bef);
  delete bef;
}

Game::~Game()
{
}

void Game::run()
{
  bool run = true;
  while(run)
  {
    input.poll();
    run = (!glfwWindowShouldClose(myGL.window) && (glfwGetKey(myGL.window, GLFW_KEY_ESCAPE) != GLFW_PRESS));
  }
}

