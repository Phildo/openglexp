#include "basic_reconciler.h"
#include "physics_component.h"
#include "geo_component.h"
#include "light_component.h"

#include "gl_include.h"

BasicReconciler::BasicReconciler()
{
}

BasicReconciler::~BasicReconciler()
{
}

void BasicReconciler::reconcile(Entity& e, EntityPool* ep) const
{
  if(e.physicsComponentIndex != -1)
  {
    PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];
    if(e.geoComponentIndex != -1)
    {
      GeoComponent& gc = ep->geoComponents[e.geoComponentIndex];

      gc.modelMatA = glm::translate(glm::mat4(), glm::vec3(pc.pos.x, pc.pos.y, pc.pos.z));

      gc.modelMatR = glm::rotate(glm::mat4(), pc.rot.y, glm::vec3(0.0,1.0,0.0)); //yaw
      gc.modelMatR = glm::rotate(gc.modelMatR, pc.rot.x,   glm::vec3(1.0,0.0,0.0)); //pitch
      gc.modelMatR = glm::rotate(gc.modelMatR, pc.rot.z,  glm::vec3(0.0,0.0,1.0)); //roll
    }
    if(e.lightComponentIndex != -1)
    {
      //not the most efficient thing in the world... but it works
      LightComponent& lc = ep->lightComponents[e.lightComponentIndex];
      lc.pos.x = pc.pos.x;
      lc.pos.y = pc.pos.y;
      lc.pos.z = pc.pos.z;
    }
  }
}

