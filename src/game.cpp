#include "game.h"

#include "mygl.h"
#include "input.h"
#include "entity_system/entity_system.h"

#include <stdio.h>
#include <iostream>

#include "basic_entity_factory.h"
#include "light_entity_factory.h"
#include "camera_entity_factory.h"

#define DEBUG
#define MS_PER_TICK (1000/60)
#define MAX_CATCH_UP_TICKS 100

Game::Game()
{
  myGL = new MyGL();
  input = new Input(myGL);
  entitySystem = new EntitySystem();

  BasicEntityFactory *bef  = new BasicEntityFactory();  for(int i = 0; i < 2; i++) entitySystem->produceEntityFromFactory(bef); delete bef;
  LightEntityFactory *lef  = new LightEntityFactory();  for(int i = 0; i < 1; i++) entitySystem->produceEntityFromFactory(lef); delete lef;
  CameraEntityFactory *cef = new CameraEntityFactory(); for(int i = 0; i < 1; i++) entitySystem->produceEntityFromFactory(cef); delete cef;
}

#define msPassed(f,t) ((t-f)*1000)
void Game::run()
{
  bool run = true;
  bool render = false;

  double now_stamp = glfwGetTime();
  double tick_stamp = now_stamp;
  #ifdef DEBUG
  double debug_stamp = now_stamp;
  #endif

  int ms_til_tick = 0;
  int catch_up_count = 0;

  while(run)
  {
    now_stamp = glfwGetTime();
    if(msPassed(tick_stamp,now_stamp) > ms_til_tick)
      ms_til_tick -= msPassed(tick_stamp,now_stamp);

    while(ms_til_tick <= 0 && catch_up_count < MAX_CATCH_UP_TICKS)
    {
      ms_til_tick += MS_PER_TICK;
      input->poll();

      entitySystem->update(*input);
      render = true;

      tick_stamp = glfwGetTime();
      catch_up_count++;
    }
    catch_up_count = 0;

    if(render)
    {
      #ifdef DEBUG
      now_stamp = glfwGetTime();
      std::cout << (int)(1/((msPassed(debug_stamp,now_stamp)+0.00001)/1000.0)) << std::endl;
      debug_stamp = glfwGetTime();
      #endif
      entitySystem->render();
      glfwSwapBuffers(myGL->window);
      render = false;
    }
    run = (!glfwWindowShouldClose(myGL->window) && (glfwGetKey(myGL->window, GLFW_KEY_ESCAPE) != GLFW_PRESS));
  }
}

Game::~Game()
{
  delete entitySystem;
  delete input;
  delete myGL;
}

