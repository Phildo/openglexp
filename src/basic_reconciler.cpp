#include "basic_reconciler.h"
#include "physics_component.h"
#include "geo_component.h"

#include "gl_include.h"

BasicReconciler::BasicReconciler()
{
}

BasicReconciler::~BasicReconciler()
{
}

void BasicReconciler::reconcile(Entity& e, EntityPool* ep) const
{
  if(e.geoComponentIndex != -1 && e.physicsComponentIndex != -1)
  {
    PhysicsComponent& pc = ep->physicsComponents[e.physicsComponentIndex];
    GeoComponent& gc = ep->geoComponents[e.geoComponentIndex];

    gc.modelMat = glm::translate(glm::mat4(), glm::vec3(pc.x, pc.y, pc.z));
    gc.modelMat = glm::rotate(gc.modelMat, pc.rotPitch, glm::vec3(0.0,1.0,0.0));
    gc.modelMat = glm::rotate(gc.modelMat, pc.rotYaw,   glm::vec3(1.0,0.0,0.0));
    gc.modelMat = glm::rotate(gc.modelMat, pc.rotRoll,  glm::vec3(0.0,0.0,1.0));
  }
}

