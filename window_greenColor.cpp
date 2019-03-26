#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

void draw(void)
{
  glClearColor(0,1,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,640.0,0.0,480.0);
  glColor3f(1,0,0);


 /* start drawing your object from here */

   glBegin(GL_POINTS);
    
      glVertex2f(100,100);
      glVertex2f(200,100);
      
   glEnd();


 /*                                         */

   glFlush();

}

 int main(int argc, char**argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
   glutInitWindowPosition(30,50);
   glutInitWindowSize(500,500);
   glutCreateWindow("OpenGL program for initializing window of green color");
   glutDisplayFunc(draw);
   glutMainLoop();
   return 0;
}


