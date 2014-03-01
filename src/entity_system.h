#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

class Graphics;
class EntityPool;
class PhysicsSolver;
class BasicReconciler;
class WorldRenderer;
class HUDRenderer;
class Camera;

class EntityFactory;
struct GLFWwindow;

class EntitySystem
{
  private:
    Graphics* graphics;
    EntityPool* pool;

    PhysicsSolver* physics_solver;
    WorldRenderer* world_renderer;
    HUDRenderer* hud_renderer;
    BasicReconciler* b_reconciler;

    Camera* cam;
  public:
    EntitySystem(Graphics* g);
    ~EntitySystem();
    void produceEntityFromFactory(EntityFactory* ef);

    void solve();
    void reconcile();
    void render(GLFWwindow* window) const;
};

#endif

