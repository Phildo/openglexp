#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

class EntityPool;
class PhysicsSolver;
class BasicReconciler;
class WorldRenderer;
class Camera;

class EntityFactory;
struct GLFWwindow;

class EntitySystem
{
  private:
    EntityPool *pool;

    PhysicsSolver *physics_solver;
    WorldRenderer *world_renderer;
    BasicReconciler *b_reconciler;

    Camera *cam;
  public:
    EntitySystem();
    ~EntitySystem();
    void produceEntityFromFactory(EntityFactory* ef);

    void solve();
    void reconcile();
    void render(GLFWwindow* window) const;
};

#endif

