#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

struct GLFWwindow;

class Graphics
{
  private:
    GLFWwindow* window;
  public:
    Graphics(GLFWwindow* win);
    void render();
};

#endif

