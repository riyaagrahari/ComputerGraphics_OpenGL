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

void bound_it(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_it(x+1,y,fillColor,bc);
        bound_it(x-2,y,fillColor,bc);
        bound_it(x,y+2,fillColor,bc);
        bound_it(x,y-2,fillColor,bc);
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
	glColor3f(0.0,0.0,1.0);
	glVertex2i(-20,-180);
	glVertex2i(-20,100);
	glVertex2i(-160,100);
	glVertex2i(-160,150);
	glVertex2i(160,150);
	glVertex2i(160,100);
	glVertex2i(20,100);
	glVertex2i(20,-180);
	glEnd();
	 
}

	

void plotImage()
{
	polygon();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2i(-80,-90);
	glVertex2i(-80,-40);
	glVertex2i(-40,-40);
	glVertex2i(-40,-90);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(-130,10);
	glVertex2i(-130,60);
	glVertex2i(-90,60);
	glVertex2i(-90,10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(80,-90);
	glVertex2i(80,-40);
	glVertex2i(40,-40);
	glVertex2i(40,-90);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(130,10);
	glVertex2i(130,60);
	glVertex2i(90,60);
	glVertex2i(90,10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(-160,160);
	glVertex2i(-160,215);
	glVertex2i(-125,215);
	glVertex2i(-125,160);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(160,160);
	glVertex2i(160,215);
	glVertex2i(125,215);
	glVertex2i(125,160);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(-20,160);
	glVertex2i(-20,215);
	glVertex2i(20,215);
	glVertex2i(20,160);
	glEnd();
	glFlush();
	float bCol[] = {1,1,1};
        float color[] = {0,0,1};
            //glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,intCol);
	//bound_it(-60,-90,color,bCol);
	glFlush();
}

void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	gluOrtho2D(-320,320,-240,240);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-300.0,-230.0);
	glVertex2f(-300.0,230.0);
	glVertex2f(300.0,230.0);
	glVertex2f(300.0,-230.0);
	glEnd();
	glFlush();
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
