#include "basic_entity_factory.h"

#include "entity.h"
#include "entity_pool.h"
#include "geo_component.h"

#include "FLAT_utils.h"
#include "gl_include.h"

BasicEntityFactory::BasicEntityFactory()
{
}

BasicEntityFactory::~BasicEntityFactory()
{
}

void BasicEntityFactory::produce(EntityPool* ep)
{
  Entity& e = ep->createEntity( ComponentSig_Physics | ComponentSig_Geo );  

  GeoComponent& gc = ep->geoComponents[e.geoComponentIndex];

  gc.pos[0] = glm::vec3( 5.0f,-5.0f,0.2f);
  gc.pos[1] = glm::vec3( 0.0f, 5.0f,0.2f);
  gc.pos[2] = glm::vec3(-5.0f,-5.0f,0.2f);
  gc.pos[3] = glm::vec3(-5.0f,-5.0f,-0.2f);
  gc.pos[4] = glm::vec3( 0.0f, 5.0f,-0.2f);
  gc.pos[5] = glm::vec3( 5.0f,-5.0f,-0.2f);

  gc.color[0] = glm::vec3(FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f);
  gc.color[1] = glm::vec3(FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f);
  gc.color[2] = glm::vec3(FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f);
  gc.color[3] = glm::vec3(FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f);
  gc.color[4] = glm::vec3(FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f);
  gc.color[5] = glm::vec3(FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f,FLAT_Utils::randf()+0.2f);

  gc.norm[0] = glm::vec3(0.0f,0.0f,1.0f);
  gc.norm[1] = glm::vec3(0.0f,0.0f,1.0f);
  gc.norm[2] = glm::vec3(0.0f,0.0f,1.0f);
  gc.norm[3] = glm::vec3(0.0f,0.0f,-1.0f);
  gc.norm[4] = glm::vec3(0.0f,0.0f,-1.0f);
  gc.norm[5] = glm::vec3(0.0f,0.0f,-1.0f);

  gc.numVerts = 6;

  PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];

  pc.rotVel.y = (FLAT_Utils::randf()-0.5f)*2;
  pc.rotVel.x = (FLAT_Utils::randf()-0.5f)*2;
  pc.rotVel.z = (FLAT_Utils::randf()-0.5f)*2;

  pc.rot.y = (FLAT_Utils::randf())*200;
  pc.rot.x = (FLAT_Utils::randf())*200;
  pc.rot.z = (FLAT_Utils::randf())*200;
}

