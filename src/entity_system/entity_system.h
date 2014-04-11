#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

class EntityPool;
class Models;
class EntityFactory;

class PhysicsSolver;
class WorldRenderer;
class HudRenderer;

class Input;

class EntitySystem
{
  private:
    EntityPool* pool;
    Models* models; //this is dumb

    PhysicsSolver* physics_solver;
    WorldRenderer* world_renderer;
    HudRenderer* hud_renderer;
  public:
    EntitySystem();
    ~EntitySystem();
    void produceEntityFromFactory(EntityFactory* ef);

    void update(Input& i);
    void render() const;
};

#endif

