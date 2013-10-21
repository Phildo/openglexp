
#include <GLUT/GLUT.h>

void display(void)
{
  glClearColor(255,255,255,0);
  glColor3d(0,0,0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_QUADS);
  glVertex2i(0,0);
  glVertex2i(0,128);
  glVertex2i(128,128);
  glVertex2i(128,0);
  glEnd();

  glRecti(200,200,250,250);
  glutSwapBuffers();
}

void reshape(int width, int height)
{
  glViewport(0,0,width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(0,width,height,0);
  glMatrixMode(GL_MODELVIEW);
}

void idle(void)
{
  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(640, 480);

  glutCreateWindow("TEST");

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);

  glutMainLoop();
  return 0;
}

