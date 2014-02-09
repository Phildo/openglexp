#include "entity_system.h"
#include "entity_pool.h"
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

void render(GLFWwindow* window)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  for(int i = 0; i < renderComponents.length; i++)
  {
    b_renderer.loadVertData(renderComponents[i]);
    b_renderer.render(cam, renderComponents[i]);
  }
  glfwSwapBuffers(window);
}

