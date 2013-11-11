#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

struct GLFWwindow;

class Graphics
{
  private:
    GLFWwindow* window;
    GLuint vertBufferID;
    GLuint vertArrayID;
  public:
    Graphics(GLFWwindow* win);
    ~Graphics();
    void render();
};

#endif

