#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;

void display(void)
{

glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0,480.0);
glColor3f(1, 0, 0);

glBegin(GL_LINE_STRIP);
int x,y,x1,y1,x2,y2,dx,dy,con;float m;
 
cout<<"Enter the coordinates (x1,y1) ";
cin>>x1>>y1;
cout<<"Enter the coordinates (x2,y2) ";
cin>>x2>>y2;
 
dx=abs(x2-x1);dy=abs(y2-y1);
if(dx >= dy)
   con=dx;
else
   con=dy;

m=dy/dx;
x=x1;
y=y1;
if(m<1)
 {
  for(int i =1;i<=con;i++)
   {
     glVertex2f(x,y);
     x=x+1;
     y=y+m;
   
     
    }
 }
else
 {
  for(int i =1;i<=con;i++)
   {
     glVertex2f(x,y);
     x=x+(1/m);
     y=y+1;
     
    }
 }
glEnd();
glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100, 100);
glutInitWindowSize(500, 500);
glutCreateWindow("DDA Line Drwaing Algorithm");
glutDisplayFunc(display);
glutMainLoop();
return 0;

}
