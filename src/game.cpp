#include "game.h"
#include "basic_entity_factory.h"

Game::Game() :
  myGL(),
  input(Input(myGL)),
  graphics(Graphics(myGL)),
  entitySystem()
{
  BasicEntityFactory *bef = new BasicEntityFactory();
  for(int i = 0; i < 500; i++)
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
    entitySystem.solve();
    entitySystem.reconcile();
    entitySystem.render(myGL.window);
    run = (!glfwWindowShouldClose(myGL.window) && (glfwGetKey(myGL.window, GLFW_KEY_ESCAPE) != GLFW_PRESS));
  }
}

