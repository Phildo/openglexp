#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

class Graphics;
class EntityPool;
class PhysicsSolver;
class InputInjector;
class BasicReconciler;
class WorldRenderer;
class HUDRenderer;
class Input;
class Camera;

class EntityFactory;
struct GLFWwindow;

class EntitySystem
{
  private:
    Graphics* graphics;
    EntityPool* pool;

    PhysicsSolver* physics_solver;
    InputInjector* input_injector;
    WorldRenderer* world_renderer;
    HUDRenderer* hud_renderer;
    BasicReconciler* b_reconciler;

    Camera* cam;
  public:
    EntitySystem(Graphics* g);
    ~EntitySystem();
    void produceEntityFromFactory(EntityFactory* ef);

    void solve();
    void input(Input& i);
    void reconcile();
    void render(GLFWwindow* window) const;
};

#endif

