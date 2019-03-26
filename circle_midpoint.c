#include <GL/glut.h>
#include<stdio.h>
#include <GL/gl.h>
#include<stdlib.h>
float r;
void display() {
 glColor3f(0.0, 1.0, 1.0);
 glPointSize(2.0);

 float x = 0, y = r;
 float p = 1 - r;
 glBegin(GL_POINTS);
 while (x != y) 
 {
  x++;
  if (p < 0) {
   p += 2 * (x + 1) + 1;
  }
  else {
   y--;
   p += 2 * (x + 1) + 1 - 2 * (y - 1);
  }
  glVertex2i(x, y);
  glVertex2i(-x, y);
  glVertex2i(x, -y);
  glVertex2i(-x, -y);
 
  glVertex2i(y, x);
  glVertex2i(-y, x);
  glVertex2i(y, -x);
  glVertex2i(-y, -x);
 
 }
 glEnd();
 glFlush();
}
void init()
{
glClearColor(0.0, 0.0, 0.0, 0.0);
 glClear(GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-250, 250, -250, 250);
 glMatrixMode(GL_PROJECTION);
}
int main(int argc, char ** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Circle Generation using mid point");
 init();
 glViewport(0, 0, 500, 500);
 printf("Enter radius of the circle\n"); 
scanf("%f",&r);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
