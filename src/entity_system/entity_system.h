#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

class EntityPool;
class EntityFactory;

class PhysicsSolver;
class WorldRenderer;
class HudRenderer;

class Graphics;
class Input;
class Camera;


class EntitySystem
{
  private:
    EntityPool* pool;

    PhysicsSolver* physics_solver;
    WorldRenderer* world_renderer;
    HudRenderer* hud_renderer;
    BasicReconciler* b_reconciler;

    Camera* cam;
  public:
    EntitySystem();
    ~EntitySystem();
    void produceEntityFromFactory(EntityFactory* ef);

    void update(Input& i);
    void render(Graphics* g) const;
};

#endif

