#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include <algorithm>
using namespace std;

int start = 0; int end = 0;

void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	gluOrtho2D(-375,375,0,750);
	glFlush();
}

void fractal(int start, int end)
{
	if(start <= end)
	{
		glBegin(GL_LINES);
		glVertex2d(0, 0);
		glVertex2d(0, 150);
		glEnd();
		glFlush();

		int angle = 30;

		glTranslated(0, 150, 0);
		glRotated(-angle, 0, 0, 1);
		glScalef(0.80,0.80,1);
			glColor4f(1,0,0,1);
			fractal(start + 1, end);
		glRotated(2*angle, 0, 0, 1);
			glColor4f(1,1,0,1);
			fractal(start + 1, end);
		glScalef(1.25,1.25,1);
		glRotated(-angle, 0, 0, 1);
		glTranslated(0, -150, 0);
		
	}
}
void key( unsigned char key, int x, int y )
{
	if (key == 32) { 
		end += 1; 
		fractal(start, end); 
	}
}

void myDisplay() {

	start = 0; end = 5;
	fractal(start, end);
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);//Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(750, 750); //Initialize the size of Window
	glutInitWindowPosition(100, 0); //Initial position of the window
	glutCreateWindow("Fractal Try 2"); //Name of the Window
	Init();
	//createMenu();
	//glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
