#include "entity_system.h"
#include "entity_pool.h"
#include "models.h"
#include "entity_factory.h"

#include "../physics_solver.h"
#include "../world_renderer.h"
#include <glm/gtc/matrix_transform.hpp>

EntitySystem::EntitySystem()
{
  pool = new EntityPool();
  models = new Models();

  physics_solver = new PhysicsSolver();
  world_renderer = new WorldRenderer();
}

void EntitySystem::produceEntityFromFactory(EntityFactory* ef)
{
  ef->produce(pool);
}


void EntitySystem::update(Input& i)
{
  this->solve();
  this->reconcile();
}

void EntitySystem::solve()
{
  for(int i = 0; i < pool->num_spacial_components; i++)
    physics_solver->solve(pool->spacial_components[i]);
}

void EntitySystem::render() const
{
  for(int i = 0; i < pool->num_camera_components; i++) //should only be 1. whatever.
    world_renderer->prepareForGeo(pool->camera_components[i]);

  world_renderer->loadModelVertData(models->models[1]);//TRIANGLE_MODEL
  for(int i = 0; i < pool->num_geometry_components; i++)
    world_renderer->renderGeo(pool->geometry_components[i]);
  world_renderer->loadModelVertData(models->models[2]);//BILBOARD_MODEL
  for(int i = 0; i < pool->num_geometry_components; i++)
    world_renderer->renderGeo(pool->geometry_components[i]);

  for(int i = 0; i < pool->num_light_components; i++)
  {
    world_renderer->prepareForShadow(pool->light_components[i]);
    for(int k = GL_TEXTURE_CUBE_MAP_POSITIVE_X; k < GL_TEXTURE_CUBE_MAP_POSITIVE_X + 6; k++)
    {
      world_renderer->prepareForShadowOrientation(k);

      world_renderer->loadShadowVertData(models->models[1]);//TRIANGLE_MODEL
      for(int j = 0; j < pool->num_geometry_components; j++)
        world_renderer->renderShadow(pool->geometry_components[j]);
      world_renderer->loadShadowVertData(models->models[2]);//BILBOARD_MODEL
      for(int j = 0; j < pool->num_geometry_components; j++)
        world_renderer->renderShadow(pool->geometry_components[j]);
    }

    world_renderer->prepareForLight();
    world_renderer->light(pool->light_components[i]);
  }
  world_renderer->blit();
}

void EntitySystem::reconcile()
{
  for(int i = 0; i < pool->num_spacial_components; i++)
  {
    SpacialComponent* sc = &pool->spacial_components[i];
    GeometryComponent* gc = sc->entity->geometry_component;
    if(gc)
    {
      gc->modelMatA = glm::translate(glm::mat4(), glm::vec3(sc->pos.x, sc->pos.y, sc->pos.z));

      gc->modelMatR = glm::rotate(glm::mat4(),  sc->rot.y, glm::vec3(0.0,1.0,0.0)); //yaw
      gc->modelMatR = glm::rotate(gc->modelMatR, sc->rot.x, glm::vec3(1.0,0.0,0.0)); //pitch
      gc->modelMatR = glm::rotate(gc->modelMatR, sc->rot.z, glm::vec3(0.0,0.0,1.0)); //roll
    }
  }
}

EntitySystem::~EntitySystem()
{
  delete world_renderer;
  delete physics_solver;
  delete pool;
}

