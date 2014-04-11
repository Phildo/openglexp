#include "entity_system.h"
#include "entity_pool.h"
#include "models.h"
#include "entity_factory.h"

#include "physics_solver.h"
#include "world_renderer.h"
#include "hud_renderer.h"

EntitySystem::EntitySystem()
{
  pool = new EntityPool();
  models = new Models();

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
  for(int i = 0; i < pool->physics_components.size(); i++)
  {
    physics_solver->solve(pool->physics_components[i]);
  }
}

void EntitySystem::render() const
{
  for(int i = 0; i < pool->camera_components.size(); i++) //should only be 1. whatever.
    world_renderer->prepareForGeo(pool->camera_components[i]);

  world_renderer->loadGeoVertData(models->triangle);
  for(int i = 0; i < pool->triangle_geometry_components.size(); i++)
    world_renderer->renderGeo(pool->triangle_geometry_components[i]);
  world_renderer->loadGeoVertData(models->bilboard);
  for(int i = 0; i < pool->bilboard_geometry_components.size(); i++)
    world_renderer->renderGeo(pool->bilboard_geometry_components[i]);

  for(int i = 0; i < pool->light_components.size(); i++)
  {
    world_renderer->prepareForShadow(pool->light_components[i]->entity->spacial_component);
    for(int k = GL_TEXTURE_CUBE_MAP_POSITIVE_X; k < GL_TEXTURE_CUBE_MAP_POSITIVE_X + 6; k++)
    {
      world_renderer->prepareForShadowOrientation(k);

      world_renderer->loadShadowVertData(models->triangle);
      for(int j = 0; j < pool->triangle_geometry_components.size(); j++)
        world_renderer->renderShadow(pool->triangle_geometry_components[j]);
      world_renderer->loadShadowVertData(models->bilboard);
      for(int j = 0; j < pool->bilboard_geometry_components.size(); j++)
        world_renderer->renderShadow(pool->bilboard_geometry_components[j]);
    }

    for(int j = 0; j < pool->camera_components.size(); j++) //should only be 1. whatever.
      world_renderer->prepareForLight(pool->camera_components[j]);
    world_renderer->light(pool->light_components[i]->entity->spacial_component);
  }
  world_renderer->blit();
  
  hud_renderer->prepareForDraw();
  for(int i = 0; i < pool->hud_components.size(); i++)
    hud_renderer->render(pool->hud_components[i]);

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

