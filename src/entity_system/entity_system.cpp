#include "entity_system.h"
#include "entity_pool.h"
#include "entity_factory.h"
#include "models.h"

#include "../physics_solver.h"
#include "../world_renderer.h"
#include <glm/gtc/matrix_transform.hpp>

EntitySystem::EntitySystem()
{
  Models::defineModels();
  pool = new EntityPool();

  physics_solver = new PhysicsSolver();
  world_renderer = new WorldRenderer();
}

void EntitySystem::debug()
{
  pool->light_components[0].entity->spacial_component->pos.x = 1;
  pool->light_components[0].entity->spacial_component->pos.y = 1;
  pool->light_components[0].entity->spacial_component->pos.z = 5;

  pool->light_components[1].entity->spacial_component->pos.x = -3;
  pool->light_components[1].entity->spacial_component->pos.y = 0;
  pool->light_components[1].entity->spacial_component->pos.z = 3;
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

void EntitySystem::reconcile()
{
  for(int i = 0; i < pool->num_spacial_components; i++)
  {
    SpacialComponent* sc = &pool->spacial_components[i];
    GeometryComponent* gc = sc->entity->geometry_component;
    if(gc)
    {
      gc->modelMatA = glm::translate(glm::mat4(), glm::vec3(sc->pos.x, sc->pos.y, sc->pos.z));

      gc->modelMatR = glm::rotate(glm::mat4(),   sc->rot.y, glm::vec3(0.0,1.0,0.0)); //yaw
      gc->modelMatR = glm::rotate(gc->modelMatR, sc->rot.x, glm::vec3(1.0,0.0,0.0)); //pitch
      gc->modelMatR = glm::rotate(gc->modelMatR, sc->rot.z, glm::vec3(0.0,0.0,1.0)); //roll
    }
  }
}

void EntitySystem::render() const
{
  world_renderer->clear();

  for(int i = 0; i < pool->num_camera_components; i++) //should only be 1. whatever.
    world_renderer->prepareForGeo(pool->camera_components[i]);

  //ECS_CONSTRUCT_MODELS_G_RENDER_START
world_renderer->loadModelVertData(BILBOARD_MODEL);
for(int i = 0; i < pool->num_geometry_bilboard_model_components; i++)
  world_renderer->renderGeo(pool->geometry_bilboard_model_components[i]);
world_renderer->loadModelVertData(CUBE_MODEL);
for(int i = 0; i < pool->num_geometry_cube_model_components; i++)
  world_renderer->renderGeo(pool->geometry_cube_model_components[i]);
world_renderer->loadModelVertData(INV_CUBE_MODEL);
for(int i = 0; i < pool->num_geometry_inv_cube_model_components; i++)
  world_renderer->renderGeo(pool->geometry_inv_cube_model_components[i]);
world_renderer->loadModelVertData(SCREEN_QUAD_MODEL);
for(int i = 0; i < pool->num_geometry_screen_quad_model_components; i++)
  world_renderer->renderGeo(pool->geometry_screen_quad_model_components[i]);
world_renderer->loadModelVertData(TRIANGLE_MODEL);
for(int i = 0; i < pool->num_geometry_triangle_model_components; i++)
  world_renderer->renderGeo(pool->geometry_triangle_model_components[i]);
  //ECS_CONSTRUCT_MODELS_G_RENDER_END

  for(int i = 0; i < pool->num_light_components; i++)
  {
    world_renderer->prepareForShadow(pool->light_components[i]);
    for(int k = GL_TEXTURE_CUBE_MAP_POSITIVE_X; k < GL_TEXTURE_CUBE_MAP_POSITIVE_X + 6; k++)
    {
      world_renderer->prepareForShadowOrientation(k);

      //ECS_CONSTRUCT_MODELS_SHADOW_RENDER_START
world_renderer->loadShadowVertData(BILBOARD_MODEL);
for(int i = 0; i < pool->num_geometry_bilboard_model_components; i++)
  world_renderer->renderShadow(pool->geometry_bilboard_model_components[i]);
world_renderer->loadShadowVertData(CUBE_MODEL);
for(int i = 0; i < pool->num_geometry_cube_model_components; i++)
  world_renderer->renderShadow(pool->geometry_cube_model_components[i]);
world_renderer->loadShadowVertData(SCREEN_QUAD_MODEL);
for(int i = 0; i < pool->num_geometry_screen_quad_model_components; i++)
  world_renderer->renderShadow(pool->geometry_screen_quad_model_components[i]);
world_renderer->loadShadowVertData(TRIANGLE_MODEL);
for(int i = 0; i < pool->num_geometry_triangle_model_components; i++)
  world_renderer->renderShadow(pool->geometry_triangle_model_components[i]);
      //ECS_CONSTRUCT_MODELS_SHADOW_RENDER_END
    }

    world_renderer->prepareForLight();
    world_renderer->light(pool->light_components[i]);
  }
  world_renderer->blit();
}

EntitySystem::~EntitySystem()
{
  delete world_renderer;
  delete physics_solver;
  delete pool;
}

