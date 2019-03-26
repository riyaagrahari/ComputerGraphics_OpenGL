#include <GL/glut.h>
#include <algorithm>
#include <iostream>
using namespace std;
float xmin = 100,ymin = 100,xmax = 300, ymax = 300;
int x1 = 0,x2 = 0,y1 = 0,y2 = 0,xc1=0,xc2=0,yc1=0,yc2=0;
int counter =0, first =0;
float t1 =0.0 , t2 = 1.0;
float p[4],q[4],r[4];
float	R=1.0,	G=1.0, B=1.0;
void plot(int , int ,int ,int );
void init()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.0,0.0,0.0,1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,500,0,500);
  glFlush();
}
void display()
{
  
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2i(xmin,ymax);
  glVertex2i(xmax,ymax);
  glVertex2i(xmax,ymin);
  glVertex2i(xmin,ymin);
  glEnd();
  R=1.0,G=1.0, B=1.0;
  glColor3f(R,G,B);
  plot(x1,y1,x2,y2);
  glFlush();
       
}
void plot(int a, int b,int c,int d)
{
 
 glBegin(GL_LINES);
 glVertex2i(a,b);
 glVertex2i(c,d);
 glEnd();
 glFlush();
}


void calculate()
{
 int deltax=x2-x1,deltay=y2-y1;
 float t;
 p[0]=-deltax;q[0]=x1-xmin;
 p[1]=deltax;q[1]=xmax-x1;
 p[2]=-deltay;q[2]=y1-ymin;
 p[3]=deltay;q[3]=ymax-y1;

 for(int i=0;i<4;i++)
{
 r[i] = q[i]/p[i];
}

for(int i=0;i<4;i++)
{
  if (p[i] < 0)
   {
	t1 = max(
r[i],t1);
	}

  if (p[i] > 0)
   {
	t2 = min(r[i],t2);
	}
}
if (t1 < t2)
{
  xc1 = x1 + deltax * t1;
  yc1 = y1 + deltay * t1;
  xc2 = x1 + deltax * t2;
  yc2 = y1 + deltay * t2;
}
  cout<<t1<<"\n";
  cout<<t2<<"\n";
 cout<<x1<<"\n"<<y1<<"\n"<<x2<<"\n"<<y2<<"\n";
  cout<<xc1<<"\n"<<yc1<<"\n"<<xc2<<"\n"<<yc2<<"\n";
x1=xc1;
x2=xc2;
y1=yc1;
y2=yc2;
 t1=0.0;
 t2 =1.0;

}

void MouseClick(int btn, int state, int x, int y)
{

          if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
                switch(first)
                {
                case 0:
                {
                        x1 = x;
                        y1 = (500-y);
                        first = 1;
                        break;
                }
                case 1:
                {
                        x2 = x;
                        y2 = (500-y);
                        plot ( x1, y1, x2, y2);
                        first = 0;
                        break;
                }
                }
}

void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: 
	R=1.0;
	G=0.0;
	B=0.0;
	glClear(GL_COLOR_BUFFER_BIT);
		
	calculate();

		
	glutPostRedisplay();
        break;
	

    default:
        break;
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Graphics Assignment 2");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyInput);
    glutMouseFunc(MouseClick);
    init(); 
    glutMainLoop();
    return 0;
}

