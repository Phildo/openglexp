#include "basic_reconciler.h"
#include "physics_component.h"
#include "render_component.h"

#include "gl_include.h"

BasicReconciler::BasicReconciler()
{
}

BasicReconciler::~BasicReconciler()
{
}

void BasicReconciler::reconcile(Entity& e, EntityPool& ep) const
{
  if(e.renderComponentIndex != -1 && e.physicsComponentIndex != -1)
  {
    PhysicsComponent& pc = ep.physicsComponents[e.physicsComponentIndex];
    RenderComponent& rc = ep.renderComponents[e.renderComponentIndex];

    rc.modelMat = glm::translate(glm::mat4(), glm::vec3(pc.x, pc.y, pc.z));
    rc.modelMat = glm::rotate(rc.modelMat, pc.rotPitch, glm::vec3(0.0,1.0,0.0));
    rc.modelMat = glm::rotate(rc.modelMat, pc.rotYaw,   glm::vec3(1.0,0.0,0.0));
    rc.modelMat = glm::rotate(rc.modelMat, pc.rotRoll,  glm::vec3(0.0,0.0,1.0));
  }
}

