#include "entity_system.h"
#include "entity_factory.h"
#include "entity_pool.h"
#include "basic_solver.h"
#include "basic_reconciler.h"
#include "world_renderer.h"
#include "camera.h"

EntitySystem::EntitySystem():pool(),b_solver(),b_reconciler(),world_renderer(),cam()
{
  pool = new EntityPool();
  b_solver = new BasicSolver();
  b_reconciler = new BasicReconciler();
  world_renderer = new WorldRenderer();

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
    b_solver->solve(pool->physicsComponents[i]);
  }
}

void EntitySystem::reconcile() 
{
  for(int i = 0; i < pool->entities.size(); i++)
  {
    b_reconciler->reconcile(pool->entities[i], pool);
  }
}

void EntitySystem::render(GLFWwindow* window) const
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for(int i = 0; i < pool->renderComponents.size(); i++)
  {
    world_renderer->loadVertData(pool->renderComponents[0]);
    world_renderer->render(cam, pool->renderComponents[i]);
  }
  glfwSwapBuffers(window);
}

EntitySystem::~EntitySystem()
{
  delete cam;
  delete world_renderer;
  delete b_reconciler;
  delete b_solver;
  delete pool;
}

