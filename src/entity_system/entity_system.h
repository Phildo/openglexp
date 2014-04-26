#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

class EntityPool;
class EntityFactory;

class PhysicsSolver;
class WorldRenderer;

class Input;

class EntitySystem
{
  private:
    EntityPool* pool;

    PhysicsSolver* physics_solver;
    WorldRenderer* world_renderer;

    void solve();
    void reconcile();
  public:
    EntitySystem();
    ~EntitySystem();
    void debug();

    void produceEntityFromFactory(EntityFactory* ef);

    void update(Input& i);
    void render() const;
};

#endif

