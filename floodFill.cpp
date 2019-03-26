#include<iostream>
#include<GL/glut.h>
#include <algorithm>
using namespace std;

int vertices=5,x,y,click = 0, i = 0,index=0, seedx, seedy;
int x_polygon[15], y_polygon[15];
void floodFill(int, int);
void mouse(int button, int press, int mx, int my){	
	if(button == GLUT_LEFT_BUTTON && press == GLUT_DOWN){
		x = mx;
		y = 500-my;
		x_polygon[click]=x;
		y_polygon[click]=y;
		click++;
		if (click == vertices){
			glBegin(GL_LINE_LOOP);
			glColor3f(0.0,1.0,0.0);
			for(int j = 0; j < vertices; j++){
				glVertex2f(x_polygon[j],y_polygon[j]);
			}
			x_polygon[vertices]=x_polygon[0], y_polygon[vertices]=y_polygon[0];
			glEnd();
			glFlush();
		}
	}
	if(button == GLUT_RIGHT_BUTTON && press == GLUT_DOWN){
		seedx = mx;
		seedy = 500-my;
		floodFill(seedx,seedy);
		
	}
}

int check(int x2, int y2){
	int R = 0, G = 0, B = 0;
	float pixel[4];
	glReadPixels(x2, y2, 1, 1, GL_RGB,  GL_FLOAT, pixel);
	R = (int)pixel[0];
	cout<<"R:"<<(int)pixel[0]<<endl;
	G = (int)pixel[1];
	cout<<"G:"<<(int)pixel[1]<<endl;
	B = (int)pixel[2];
	cout<<"B:"<<(int)pixel[2]<<endl;
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
		glColor3f(1.0f,1.0f,0.0f);
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

void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	gluOrtho2D(0,500,0,500);
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);//Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(500, 500); //Initialize the size of Window
	glutInitWindowPosition(190, 100); //Initial position of the window
	glutCreateWindow("FloodFill"); //Name of the Window
	Init();
	glutMouseFunc(mouse);
	//glutKeyboardFunc(keyboard);
	//glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}
