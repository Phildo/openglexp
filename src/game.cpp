#include "game.h"

#include "mygl.h"
#include "input.h"
#include "graphics.h"
#include "entity_system.h"
#include "scener.h"

#include <ctime>
#include <sys/time.h>
#include <stdio.h>
#include <iostream>

#include "basic_entity_factory.h"

//#define DEBUG
#define MS_PER_TICK 1000/60
#define MAX_CATCH_UP_TICKS 100

Game::Game()
{
  myGL = new MyGL();
  input = new Input(myGL);
  graphics = new Graphics(myGL);
  entitySystem = new EntitySystem(graphics);
  scener = new Scener();

  BasicEntityFactory *bef = new BasicEntityFactory();
  for(int i = 0; i < 10; i++)
    entitySystem->produceEntityFromFactory(bef);
  delete bef;
}

#define msPassed(f,t) ((t.tv_sec-f.tv_sec)*1000+(t.tv_usec-f.tv_usec)/1000)
void Game::run()
{
  bool run = true;
  bool render = false;
  timeval now_stamp; gettimeofday(&now_stamp, NULL);
  timeval tick_stamp = now_stamp;
  int ms_til_tick = 0;
  int catch_up_count = 0;
  while(run)
  {
    gettimeofday(&now_stamp, NULL);
    if(msPassed(tick_stamp,now_stamp) > ms_til_tick)
      ms_til_tick -= msPassed(tick_stamp,now_stamp);

    while(ms_til_tick <= 0 && catch_up_count < MAX_CATCH_UP_TICKS)
    {
      ms_til_tick += MS_PER_TICK;
      input->poll();

      entitySystem->solve();
      entitySystem->reconcile();
      render = true;

      #ifdef DEBUG
      std::cout << msPassed(tick_stamp,now_stamp) << std::endl;
      #endif
      tick_stamp = now_stamp;
      catch_up_count++;
    }
    catch_up_count = 0;

    if(render) entitySystem->render(myGL->window);
    run = (!glfwWindowShouldClose(myGL->window) && (glfwGetKey(myGL->window, GLFW_KEY_ESCAPE) != GLFW_PRESS));
  }
}

Game::~Game()
{
  delete scener;
  delete entitySystem;
  delete graphics;
  delete input;
  delete myGL;
}

