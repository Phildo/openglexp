#include "entity_system.h"
#include "graphics.h"
#include "entity_factory.h"
#include "entity_pool.h"
#include "physics_solver.h"
#include "basic_reconciler.h"
#include "world_renderer.h"
#include "hud_renderer.h"
#include "camera.h"

EntitySystem::EntitySystem(Graphics* g)
{
  graphics = g;

  pool = new EntityPool();
  physics_solver = new PhysicsSolver();
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

void EntitySystem::render(GLFWwindow* window) const
{
  world_renderer->prepareForDraw();
  for(int i = 0; i < pool->worldComponents.size(); i++)
  {
    world_renderer->loadVertData(pool->worldComponents[i]);
    world_renderer->render(cam, pool->worldComponents[i]);
  }
  world_renderer->prepareForDraw();
  world_renderer->light();
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
  delete physics_solver;
  delete pool;
}

