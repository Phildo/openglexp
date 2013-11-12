#include "game.h"

#include "gl_include.h"

#include <stdio.h>
#include <stdlib.h>

void err(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, char **argv)
{
  glfwSetErrorCallback(err);
  glfwInit();

  Game g;
  g.run();

  glfwTerminate();

  exit(EXIT_SUCCESS);
}

