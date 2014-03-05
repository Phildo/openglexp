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
#include "bilboard_entity_factory.h"

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
  BilboardEntityFactory *bbef = new BilboardEntityFactory();
  for(int i = 0; i < 200; i++)
    entitySystem->produceEntityFromFactory(bef);
  entitySystem->produceEntityFromFactory(bbef);
  delete bbef;
  delete bef;
}

#define msPassed(f,t) ((t.tv_sec-f.tv_sec)*1000+(t.tv_usec-f.tv_usec)/1000)
void Game::run()
{
  bool run = true;
  bool render = false;

  timeval now_stamp; gettimeofday(&now_stamp, NULL);
  timeval tick_stamp = now_stamp;
  #ifdef DEBUG
  timeval debug_stamp = now_stamp;
  #endif

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

      gettimeofday(&tick_stamp, NULL);
      catch_up_count++;
    }
    catch_up_count = 0;

    if(render)
    {
      #ifdef DEBUG
      gettimeofday(&now_stamp, NULL);
      if(msPassed(debug_stamp,now_stamp) > 0)
        std::cout << (int)(1/(double(msPassed(debug_stamp,now_stamp))/1000.0)) << std::endl;
        gettimeofday(&debug_stamp, NULL);
      #endif
     entitySystem->render(myGL->window);
     render = false;
    }
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

