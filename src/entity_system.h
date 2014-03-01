#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

class EntityPool;
class BasicSolver;
class BasicReconciler;
class WorldRenderer;
class Camera;

class EntityFactory;
struct GLFWwindow;

class EntitySystem
{
  private:
    EntityPool *pool;

    BasicSolver *b_solver;
    BasicReconciler *b_reconciler;
    WorldRenderer *world_renderer;

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

