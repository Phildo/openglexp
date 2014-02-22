#include "entity_system.h"
#include "entity_factory.h"

EntitySystem::EntitySystem():pool(),b_renderer(),cam()
{
}

EntitySystem::~EntitySystem()
{
}

void EntitySystem::produceEntityFromFactory(EntityFactory* ef)
{
  ef->produce(pool);
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

