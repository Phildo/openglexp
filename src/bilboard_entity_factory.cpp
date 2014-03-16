#include "bilboard_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "geo_component.h"

#include "gl_include.h"

BilboardEntityFactory::BilboardEntityFactory()
{
}

BilboardEntityFactory::~BilboardEntityFactory()
{
}

void BilboardEntityFactory::produce(EntityPool* ep)
{
  Entity& e = ep->createEntity(ComponentSig_Geo);  

  GeoComponent& gc = ep->geoComponents[e.geoComponentIndex];
  gc.pos[0] = glm::vec3(-15.0,-10.0,-8.0);
  gc.pos[1] = glm::vec3(-15.0, 10.0,-8.0);
  gc.pos[2] = glm::vec3( 15.0, 10.0,-8.0);
  gc.pos[3] = glm::vec3(-15.0,-10.0,-8.0);
  gc.pos[4] = glm::vec3( 15.0, 10.0,-8.0);
  gc.pos[5] = glm::vec3( 15.0,-10.0,-8.0);
  gc.color[0] = glm::vec3(0.8,0.2,0.2);
  gc.color[1] = glm::vec3(0.2,0.2,0.2);
  gc.color[2] = glm::vec3(0.2,0.8,0.2);
  gc.color[3] = glm::vec3(0.8,0.2,0.2);
  gc.color[4] = glm::vec3(0.2,0.8,0.2);
  gc.color[5] = glm::vec3(0.2,0.2,0.2);
  gc.norm[0] = glm::vec3(0.0,0.0,1.0);
  gc.norm[1] = glm::vec3(0.0,0.0,1.0);
  gc.norm[2] = glm::vec3(0.0,0.0,1.0);
  gc.norm[3] = glm::vec3(0.0,0.0,1.0);
  gc.norm[4] = glm::vec3(0.0,0.0,1.0);
  gc.norm[5] = glm::vec3(0.0,0.0,1.0);
  gc.numVerts = 6;
}

