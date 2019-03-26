#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int x =0,y=0,click=0,vertices=3;
int x_polygon[50], y_polygon[50];
 int coeff[50]; // since vertices=4
int plotpt=1000;
float blend = 0.0000f;	int xc[1000]; int yc[1000];

void beizer(int);

void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	gluOrtho2D(-250,250,-250,250);
	glFlush();
}

void mouse(int button, int press, int mx, int my){	
	if(button == GLUT_LEFT_BUTTON && press == GLUT_DOWN){
		x = mx - 250;
		y = 250 - my;
		x_polygon[click]=x;
		y_polygon[click]=y;
		click++;
		if (click == vertices){
			glPointSize(2.0f);
			glBegin(GL_POINTS);
			
			glColor3f(1.0,0.0,0.0);
			for(int j = 0; j < vertices; j++){
				glVertex2f(x_polygon[j],y_polygon[j]);
				cout<<"Done"<<x_polygon[j]<<endl;
			}
			//x_polygon[vertices - 1]=x_polygon[0], y_polygon[vertices - 1]=y_polygon[0];
			glEnd();
			glFlush();
			glPointSize(1.0f);

			beizer(plotpt);
			cout<<"beizer drawn"<<endl;
			glFlush();
			click = 0;
			//glutPostRedisplay();
	
		}
		
	}

}

/*void key( unsigned char key, int x, int y )
{
	
}*/
void compute(float u, int *xc,int *yc)
{
	//Sigma Function
	for(int k = 0 ; k <= vertices - 1 ; k++)
	{
		cout<<"value of u"<<u<<endl;
		blend= coeff[k] * (float)pow(u,k) * (float)pow(1-u,vertices - 1-k);
		cout<<"pow: " <<(float)pow(u,k)<<endl;
		cout<<"blend: " <<blend<<endl;
		*xc = *xc + x_polygon[k]*blend;
		*yc = *yc + y_polygon[k]*blend;
	cout<<"beizer point k:"<<*xc<<" | "<<*yc<<endl;
	}
	
	
}
void beizer(int plotpt)
{
// calculation of binomial coefficients
	
	for(int k=0;k<=vertices - 1;k++)
	{
		coeff[k]=1;
		for(int i=k+1;i<=vertices - 1;i++)
		{
			coeff[k]=coeff[k]*i;
		}
		for(int i=2;i<=vertices - 1-k;i++)
		{
			coeff[k]=coeff[k]/i;
		}
	}


	// taking various values of parameter u
	float u = 0.0f;
	
	
	for(int i=0;i<=plotpt;i++)
	{
		xc[i]=0;yc[i]=0;
	}
	for(int i=0;i<=plotpt;i++)
	{
		//xc[i]=0;yc[i]=0;
		u = (float)i/plotpt;
		compute(u, &xc[i],&yc[i]);
		glBegin(GL_POINTS);
		glColor3f(.0f,1.0f,0.0f);
		glVertex2i(xc[i],yc[i]);
		/*glVertex2i(xc[i] * -1 , yc[i] * -1);
		glVertex2i(xc[i] , yc[i] * -1);
		glVertex2i(xc[i] * -1 , yc[i] );*/
		glEnd();
		glFlush();
		//cout<<"beizer point k:"<<xc[i]<<" | "<<yc[i]<<endl;
		
	}

}

void myDisplay() {
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINES);	
	glVertex2f(-250, 0);
	glVertex2f(250, 0);
	glVertex2f(0, -250);
	glVertex2f(0, 250);
	glEnd();
	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);//Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(500, 500); //Initialize the size of Window
	glutInitWindowPosition(0, 0); //Initial position of the window
	glutCreateWindow("Bezier Any Shape"); //Name of the Window
	Init();
	//createMenu();
	glutMouseFunc(mouse);
	//glutKeyboardFunc(key);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
