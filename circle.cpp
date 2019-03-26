#include<GL/glut.h>
#include<stdio.h>
#include <GL/gl.h>
#include<stdlib.h>
#include <math.h>
#define PI 3.14
float radius ;
void display (void)
 {
 

 glBegin(GL_LINE_LOOP);
 glPointSize(2.0);
for(int i =0; i <= 360; i++){
double angle = 2 * PI * i / 360;
double x = radius * cos(angle);
double y = radius * sin(angle);
 glColor3f (0.0, 1.0, 0.0);
 glVertex2d(x,y);
}
 glEnd(); 
 glFlush();
 }
 void init(void)
 {
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glClear (GL_COLOR_BUFFER_BIT);
 gluOrtho2D(-250, 250, -250, 250);
 }

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("CIRCLE IMPLEMENTATION ");
printf("Enter radius of the circle\n"); 
scanf("%f",&radius);
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
