#include "entity_system.h"
#include "entity_pool.h"
#include "entity_factory.h"

#include "physics_solver.h"
#include "world_renderer.h"
#include "hud_renderer.h"

EntitySystem::EntitySystem()
{
  pool = new EntityPool();

  physics_solver = new PhysicsSolver();
  world_renderer = new WorldRenderer();
  hud_renderer = new HUDRenderer();
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

void EntitySystem::render() const
{
  world_renderer->prepareForGeo(cam);
  for(int i = 0; i < pool->geoComponents.size(); i++)
  {
    world_renderer->loadGeoVertData(pool->geoComponents[i]);
    world_renderer->renderGeo(pool->geoComponents[i]);
  }
  for(int i = 0; i < pool->lightComponents.size(); i++)
  {
    world_renderer->prepareForShadow(pool->lightComponents[i]);
    for(int k = GL_TEXTURE_CUBE_MAP_POSITIVE_X; k < GL_TEXTURE_CUBE_MAP_POSITIVE_X + 6; k++) //0-5, I think...
    {
      world_renderer->prepareForShadowOrientation(k);
      for(int j = 0; j < pool->geoComponents.size(); j++)
      {
        world_renderer->loadShadowVertData(pool->geoComponents[j]);
        world_renderer->renderShadow(pool->geoComponents[j]);
      }
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
  delete b_reconciler;
  delete hud_renderer;
  delete world_renderer;
  delete physics_solver;
  delete pool;
}

