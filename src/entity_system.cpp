#include "entity_system.h"
#include "graphics.h"
#include "entity_factory.h"
#include "entity_pool.h"
#include "physics_solver.h"
#include "input_injector.h"
#include "basic_reconciler.h"
#include "world_renderer.h"
#include "hud_renderer.h"
#include "camera.h"

EntitySystem::EntitySystem(Graphics* g)
{
  graphics = g;

  pool = new EntityPool();
  physics_solver = new PhysicsSolver();
  input_injector = new InputInjector();
  world_renderer = new WorldRenderer(graphics);
  hud_renderer = new HUDRenderer(graphics);
  b_reconciler = new BasicReconciler();

  cam = new Camera();
}

void EntitySystem::produceEntityFromFactory(EntityFactory* ef)
{
  ef->produce(pool);
}

void EntitySystem::solve()
{
  for(int i = 0; i < pool->physicsComponents.size(); i++)
  {
    physics_solver->solve(pool->physicsComponents[i]);
  }
}

void EntitySystem::input(Input& in)
{
  for(int i = 0; i < pool->inputPlanarComponents.size(); i++)
  {
    input_injector->inject(in, pool->inputPlanarComponents[i]);
  }
}

void EntitySystem::render(GLFWwindow* window) const
{
  world_renderer->prepareForGeo(cam);
  for(int i = 0; i < pool->geoComponents.size(); i++)
  {
    world_renderer->loadGeoVertData(pool->geoComponents[i]);
    world_renderer->renderGeo(pool->geoComponents[i]);
  }
  for(int i = 0; i < pool->lightComponents.size(); i++)
  {
    world_renderer->prepareForShadow(cam);
    for(int j = 0; j < pool->geoComponents.size(); j++)
    {
      world_renderer->loadShadowVertData(pool->geoComponents[j]);
      world_renderer->genShadowMap(pool->lightComponents[i]);
    }
    world_renderer->prepareForLight(cam);
    world_renderer->light(pool->lightComponents[i]);
  }
  world_renderer->blit();
  
  hud_renderer->prepareForDraw();
  for(int i = 0; i < pool->HUDComponents.size(); i++)
    hud_renderer->render(pool->HUDComponents[i]);

  glfwSwapBuffers(window);
}

void EntitySystem::reconcile() 
{
  for(int i = 0; i < pool->entities.size(); i++)
  {
    b_reconciler->reconcile(pool->entities[i], pool);
  }
}

EntitySystem::~EntitySystem()
{
  delete cam;
  delete b_reconciler;
  delete hud_renderer;
  delete world_renderer;
  delete input_injector;
  delete physics_solver;
  delete pool;
}

