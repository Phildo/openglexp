#include "entity_system.h"
#include "entity_factory.h"

EntitySystem::EntitySystem():pool(),b_solver(),b_reconciler(),b_renderer(),cam()
{
}

EntitySystem::~EntitySystem()
{
}

void EntitySystem::produceEntityFromFactory(EntityFactory* ef)
{
  ef->produce(pool);
}

void EntitySystem::solve()
{
  for(int i = 0; i < pool.physicsComponents.size(); i++)
  {
    b_solver.solve(pool.physicsComponents[i]);
  }
}

void EntitySystem::reconcile() 
{
  for(int i = 0; i < pool.entities.size(); i++)
  {
    b_reconciler.reconcile(pool.entities[i], pool);
  }
}

void EntitySystem::render(GLFWwindow* window) const
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for(int i = 0; i < pool.renderComponents.size(); i++)
  {
    b_renderer.loadVertData(pool.renderComponents[i]);
    b_renderer.render(cam, pool.renderComponents[i]);
  }
  glfwSwapBuffers(window);
}

