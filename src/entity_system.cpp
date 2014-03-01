#include "entity_system.h"
#include "entity_factory.h"
#include "entity_pool.h"
#include "physics_solver.h"
#include "basic_reconciler.h"
#include "world_renderer.h"
#include "hud_renderer.h"
#include "camera.h"

EntitySystem::EntitySystem()
{
  pool = new EntityPool();
  physics_solver = new PhysicsSolver();
  world_renderer = new WorldRenderer();
  hud_renderer = new HUDRenderer();
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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    world_renderer->loadVertData(pool->worldComponents[0]);
  for(int i = 0; i < pool->worldComponents.size(); i++)
  {
    world_renderer->render(cam, pool->worldComponents[i]);
  }
  world_renderer->update();
  glClear(GL_DEPTH_BUFFER_BIT);
    //hud_renderer->loadVertData(pool->HUDComponents[0]);
  for(int i = 0; i < pool->HUDComponents.size(); i++)
  {
    hud_renderer->render(pool->HUDComponents[i]);
  }
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

