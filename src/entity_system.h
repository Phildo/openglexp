#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

#include "entity_pool.h"
#include "basic_solver.h"
#include "basic_reconciler.h"
#include "basic_renderer.h"
#include "camera.h"

class EntityFactory;
struct GLFWwindow;

class EntitySystem
{
  private:
    EntityPool pool;

    BasicSolver b_solver;
    BasicReconciler b_reconciler;
    BasicRenderer b_renderer;

    Camera cam;
  public:
    EntitySystem();
    ~EntitySystem();
    void produceEntityFromFactory(EntityFactory* ef);

    void solve();
    void reconcile();
    void render(GLFWwindow* window) const;
};

#endif

