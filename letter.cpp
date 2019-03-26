#include<iostream>
#include<GL/glut.h>
#include <algorithm>
using namespace std;

int check(int x2, int y2){
	int R = 0, G = 0, B = 0;
	float pixel[4];
	glReadPixels(x2, y2, 1, 1, GL_RGB,  GL_FLOAT, pixel);
	R = (int)pixel[0];
	G = (int)pixel[1];
	B = (int)pixel[2];
	if( R == 0 && G == 0 && B == 0){
		return 1;
	}
	else {return 0;}
}

void floodFill(int x, int y){ //4 connected
	int checkColor = check(x,y);
	cout<<"checkColor:"<<checkColor<<endl;
	if( checkColor == 1){
		glBegin(GL_POINTS);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex2i(x, y);
		glEnd();
		glFlush();
		int incx= x+1;
		int decx= x-1;
		int incy= y+1;
		int decy= y-1;
		floodFill(incx,y); //Left
		floodFill(x,incy); //Top
		floodFill(decx,y); //Right
		floodFill(x,decy); //Bottom
	}
}

void plot(int x, int y, int cx, int cy)
{
	glBegin(GL_POINTS);
	glPointSize(1.0);
	glVertex2i(x+cx, y+cy);
	glEnd();
	//floodFill(cx,cy);
	glFlush();
}
void polygon()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(-20.0,-180.0);
	glVertex2f(-20.0,100.0);
	glVertex2f(-160.0,100.0);
	glVertex2f(-160.0,150.0);
	glVertex2f(160.0,150.0);
	glVertex2f(160.0,100.0);
	glVertex2f(20.0,100.0);
	glVertex2f(20.0,-180.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-300.0,-230.0);
	glVertex2f( -300.0,230.0);
	glVertex2f( 300.0,230.0);
	glVertex2f(300.0,-230.0);
	glEnd();
	glFlush();
}

void circle(int cx, int cy)
{
	int x = 0;
	int y = 25;
	float decision = 5/4 - y;
	plot(x, y, cx, cy);
	while (y > x)
	{
	if (decision < 0)
	{
		x++;
		decision = decision + (2*x+1);
	}
	else
	{
		y--;
		x++;
		decision =decision + (2*(x-y)+1);
	}
	plot(x, y, cx, cy);
	plot(x, -y, cx, cy);
	plot(-x, y, cx, cy);
	plot(-x, -y, cx, cy);
	plot(y, x, cx, cy);

	plot(-y, x, cx, cy);
	plot(y, -x, cx, cy);
	plot(-y, -x, cx, cy);
	}
}

void plotImage()
{
	polygon();
	circle(-60,-90);
	circle(-120,60);
	circle(60,-90);
	circle(120,60);
	circle(-120,200);
	circle(0,200);
	circle(120,200);
	glFlush();
}

void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	gluOrtho2D(-320,320,-240,240);
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);//Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(640, 480); //Initialize the size of Window
	glutInitWindowPosition(190, 100); //Initial position of the window
	glutCreateWindow("Viva"); //Name of the Window
	Init();
	//glutMouseFunc(mouse);
	//glutKeyboardFunc(keyboard);
	glutDisplayFunc(plotImage);
	glutMainLoop();
	return 0;
}
