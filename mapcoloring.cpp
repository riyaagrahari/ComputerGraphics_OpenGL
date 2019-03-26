//Open GL Libraries
#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include <algorithm>

#define RED 1
#define GREEN 2
#define BLUE 3

using namespace std;


int rightClickx, rightClicky;
int R = 0, G = 0, B = 0, cityCount = 0, lineCount = 0, first = 0,  x1 = 0,x2 = 0, y1 = 0, y2 = 0, id = 0, firstConnCity = 0, secondConnCity = 0;
int cityInfo[10][9];
int connection[10][10];
void floodFill(int, int);
void makeCity(int,int);
void line(int, int,int,int);
int checkId(int , int);
int createGLUTMenus();
void checkAdjacent(int);
void cityName(int, int, int);

void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	gluOrtho2D(0,1050,0,650);
	glFlush();
	for (int i = 0; i< 10; i++){
		for (int j = 0; j < 10; j++){
			connection[i][j] = 0;
		}
	}
}

void mouseMove(int mx, int my) {
	glutDetachMenu(GLUT_RIGHT_BUTTON);
}

void print_name(char string[],float x,float y) 
{  
	glRasterPos2f(x, y);

	for (int c= 0; c <= strlen(string); c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[c]);
	}
}

void mouse(int button, int press, int mx, int my){
	if (button == GLUT_LEFT_BUTTON && press == GLUT_DOWN){
		if (cityCount < 10 && lineCount == 0){
			cityName(cityCount, mx - 40, 690 - my);
			makeCity(mx, 650-my);
			cityInfo[cityCount][0] = cityCount;
			cityInfo[cityCount][1] = mx - 60;
			cityInfo[cityCount][2] = 650-my - 30;
			cityInfo[cityCount][3] = mx + 60;
			cityInfo[cityCount][4] = 650-my + 30;
			cityInfo[cityCount][5] = 0;
			cityInfo[cityCount][6] = 1;
			cityInfo[cityCount][7] = 1;
			cityInfo[cityCount][8] = 1;
			cityCount++;
			cout<<"No of city: "<<cityCount<<endl;
		}
		else if (lineCount < 13){ 
			switch(first)
		        {
				case 0:
				{
				        x1 = mx;
				        y1 = (650-my);
				        first = 1;
					firstConnCity = checkId(x1,y1);
				        break;
				}
				case 1:
				{
				        x2 = mx;
				        y2 = (650-my);
					secondConnCity = checkId(x2,y2);
				        line ( x1, y1, x2, y2);
					connection[firstConnCity][secondConnCity] = 1;
					connection[secondConnCity][firstConnCity] = 1;
				        first = 0;
					lineCount++;
					cout<<"No of Connection: "<<lineCount<<endl;
				        break;
				}
		        }
		}
		else{
			
			for (int i = 0; i < 10; i++){
				for (int j = 0; j < 9; j++){
					cout<< cityInfo[i][j]<<" ";
				}
				cout<<endl;
			}
			for (int i = 0; i< 10; i++){
				for (int j = 0; j < 10; j++){
					cout<< connection[i][j]<<" ";
				}
				cout<<endl;
			}
		}

	}
	else if (button == GLUT_RIGHT_BUTTON && press == GLUT_DOWN){
			rightClickx = mx ;
			rightClicky = 650-my;
			id = checkId(rightClickx, rightClicky);			
			createGLUTMenus();
			
	}
}


void makeCity(int xcenter, int ycenter){
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	   glVertex2f(xcenter - 60, ycenter - 30);
	   glVertex2f(xcenter + 60, ycenter - 30);
	   glVertex2f(xcenter + 60, ycenter + 30);
	   glVertex2f(xcenter - 60, ycenter + 30);
	glEnd();
	glFlush();
}
void line(int a, int b,int c,int d)
{
 
 glBegin(GL_LINES);
 glVertex2i(a,b);
 glVertex2i(c,d);
 glEnd();
 glFlush();
}

int checkId(int x, int y)
{
	for(int i=0;i<10;i++)
	{
		if (x >= cityInfo[i][1] && y >= cityInfo[i][2] && x <= cityInfo[i][3] && y <= cityInfo[i][4])
			{
				cout<<"City Id = "<<i<<endl;
				cout<<"City color"<<cityInfo[id][5]<<endl;
				cout<<"City color R"<<cityInfo[id][6]<<endl;	
				cout<<"City color G"<<cityInfo[id][7]<<endl;	
				cout<<"City color B"<<cityInfo[id][8]<<endl;					
				return i;
			}	
	
	}
}
void processMenuEvents(int option) {
float red, green, blue;

	switch (option) {
		case RED :
			cout<<"Red is selected"<<endl;
			R = 0, G = 0, B = 0;
			glColor3f(1,0,0);
			cityInfo[id][5] = 1;
			//cityInfo[id][6] = 1;			
			floodFill(rightClickx, rightClicky);
			checkAdjacent(id);
			break;
		case GREEN :
			cout<<"Green is selected"<<endl;
			R = 0, G = 0, B = 0;
			glColor3f(0,1,0);
			cityInfo[id][5] = 2;
			//cityInfo[id][7] = 1;
			floodFill(rightClickx, rightClicky);
			checkAdjacent(id);
			//glutDetachMenu(GLUT_RIGHT_BUTTON);
			break;
		case BLUE :
			cout<<"Blue is selected"<<endl;
			R = 0, G = 0, B = 0;
			glColor3f(0,0,1);
			cityInfo[id][5] = 3;
			//cityInfo[id][8] = 1;
			floodFill(rightClickx, rightClicky);
			checkAdjacent(id);
			//glutDetachMenu(GLUT_RIGHT_BUTTON);
			break;
	}
}

void checkAdjacent(int city_id)
{
	for(int i =0;i<10;i++)
	{
		int color = cityInfo[city_id][5];

		if(connection[city_id][i] == 1)
		{
                  if (color == 1)
			{
				cityInfo[i][6]=-1;
			}
		  if (color == 2)
			{
				cityInfo[i][7]=-1;
			}
		  if (color == 3)
			{
				cityInfo[i][8]=-1;
			}
		}
	}
}
int createGLUTMenus() {

	int menu;

	// create the menu and
	// tell glut that "processMenuEvents" will
	// handle the events
	menu = glutCreateMenu(processMenuEvents);
                  if (cityInfo[id][6] != -1)
			{
				glutAddMenuEntry("RED",RED);
			}
		  if (cityInfo[id][7] != -1)
			{
				glutAddMenuEntry("GREEN",GREEN);
			}
		  if (cityInfo[id][8] != -1)
			{
				
				glutAddMenuEntry("BLUE",BLUE);
			}
	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);

return 0;
}

void cityName(int local, int xPos, int yPos){
	switch(local){
		case 0:{ print_name("Shimla", xPos, yPos); break;  }
		case 1:{ print_name("Chakrata", xPos, yPos); break;  }
		case 2:{ print_name("Mussoorie", xPos, yPos); break;  }
		case 3:{ print_name("Chamba", xPos, yPos); break;  }
		case 4:{ print_name("Rishikesh", xPos, yPos); break;  }
		case 5:{ print_name("Dehradun", xPos, yPos); break;  }
		case 6:{ print_name("Vikasnagar", xPos, yPos); break;  }
		case 7:{ print_name("Delhi", xPos, yPos); break;  }
		case 8:{ print_name("Roorkee", xPos, yPos); break;  }
		case 9:{ print_name("Haridwar", xPos, yPos); break;  }
	}
}

int check(int x2, int y2){
	
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

void myDisplay() {

	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);//Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(1050, 650); //Initialize the size of Window
	glutInitWindowPosition(0, 0); //Initial position of the window
	glutCreateWindow("Map Colouring"); //Name of the Window
	Init();
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(mouseMove);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}

