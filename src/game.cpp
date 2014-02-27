#include "game.h"
#include "basic_entity_factory.h"

#include "mygl.h"
#include "input.h"
#include "graphics.h"
#include "entity_system.h"

Game::Game()
{
  myGL = new MyGL();
  input = new Input(myGL);
  graphics = new Graphics(myGL);
  entitySystem = new EntitySystem();

  BasicEntityFactory *bef = new BasicEntityFactory();
  for(int i = 0; i < 50000; i++)
    entitySystem->produceEntityFromFactory(bef);
  delete bef;
}

void Game::run()
{
  bool run = true;
  while(run)
  {
    input->poll();
    entitySystem->solve();
    entitySystem->reconcile();
    entitySystem->render(myGL->window);

    run = (!glfwWindowShouldClose(myGL->window) && (glfwGetKey(myGL->window, GLFW_KEY_ESCAPE) != GLFW_PRESS));
  }
}

Game::~Game()
{
  delete entitySystem;
  delete graphics;
  delete input;
  delete myGL;
}

