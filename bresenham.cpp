#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>
#include <string.h>
float x1;
float y1;
float x2;
float y2;
int counter=0;
void plot(float a,float b)
{
 glBegin(GL_POINTS);
 glVertex2f(a,b);
 glEnd();
}
void Bresenham(int x0, int y0, int x1,int y1)
{
    float dx=x1-x0;
        float dy=y1-y0;
        float x=x0,y=y0;
        float m=dy/dx;
        while(x!=x1)
        {
        if(m>0 && m<1)
            {
            float p0=2*dy-dx;
            static float p1=p0;
            static float p5=p0;
            if(dx>0)
               {
                
                if(p1<0)
                {
                glColor3f(0.0, 0.0, 1.0);
               	plot(x,y);
                   p1= p1+2*dy;
                x=x+1;
                }
                else
                {
                 glColor3f(0.0, 0.0, 1.0);
                plot(x,y);
                p1=p1+2*dy-2*dx;
                y=y+1;
                x=x+1;              
                }
               }
            else
               {
                
                if(p5<0)
                {
                 glColor3f(0.0, 1.0, 1.0);
                plot(x,y);
                   p5= p5+2*dy-2*dx;
                x=x-1;
                y=y-1;
                }
                else
                {
                glColor3f(0.0, 1.0, 1.0);
                plot(x,y);
                p5=p5+2*dy;
                x=x-1;
                    }
               }
              
            }
        if(m>1)
        {
            float p0=2*dx-dy;
            static float p2=p0;
            static float p6=p0;  
            if(dx>0)
               {
                if(p2<0)
                {glColor3f(1.0, 1.0, 0.0);
                 plot(x,y);
                   p2= p2+2*dx;
                y=y+1;
                }
                else
                {glColor3f(1.0, 1.0, 0.0);
                plot(x,y);
                p2=p2+2*dx-2*dy;
                y=y+1;
                x=x+1;              
                }
               }
            else
               {
                if(p6<0)
                {glColor3f(0.0, 1.0, 0.0);
               plot(x,y);
                   p6= p6-2*dy+2*dx;
                x=x-1;
                y=y-1;
                }
                else
                {glColor3f(0.0, 1.0, 0.0);
               plot(x,y);
                p6=p6+2*dx;
                y=y-1;
                    }
               }
              
            }
        if(m<(-1))
        {
            float p0=2*dx+dy;
            static float p3=p0;
            static float p7=p0;  
            if(dx<0)
               {
                if(p3<0)
                {glColor3f(1.0, 0.0, 0.0);
                plot(x,y);
                   p3= p3+2*dx+2*dy;
                x=x-1;              
                y=y+1;
                }
                else
                {glColor3f(1.0, 0.0, 0.0);
               plot(x,y);
                p3=p3+2*dx;
                y=y+1;          
                }
               }
            else
               {
                if(p7<0)
                {glColor3f(1.0, 0.0, 1.0);
                plot(x,y);
                   p7= p7+2*dx;
                y=y-1;
                }
                else
                {glColor3f(1.0, 0.0, 1.0);
                plot(x,y);
                p7=p7+2*dx+2*dy;
                y=y-1;
                x=x+1;
                    }
               }
              
            }
        if(m>(-1) && m<0)
        {
            float p0=2*dx+dy;
            static float p4=p0;
            static float p8=p0;  
            if(dx<0)
               {
                if(p4<0)
                {glColor3f(1.0, 1.0, 1.0);
                plot(x,y);
                   p4= p4+2*dy;
                x=x-1;
                }
                else
                {glColor3f(1.0, 1.0, 1.0);
                plot(x,y);
                p4=p4+2*dy+dx;
                y=y+1;
                x=x-1;          
                }
               }
            else
               {
                if(p8<0)
                {glColor3f(1.0, 0.0, 1.0);
                plot(x,y);
                   p8= p8+2*dx+2*dy;
                y=y-1;
                x=x+1;
                }
                else
                {glColor3f(1.0, 0.0, 1.0);
                plot(x,y);
                p8=p8+2*dy;
                x=x+1;
                    }
               }
              
            }
        }
        char buffer[10]={'\0'};
        sprintf(buffer, "%f",m);
        glRasterPos2f(x1,y1+10);
        int length=strlen(buffer);
        for(int i=0 ; i<length ; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,buffer[i]);
            }



}

void color(float x, float y, char str[])
{
    
    glRasterPos2f(x,y);
	for(int i=0;i<strlen(str);i++)
  {
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15,str[i]);
  }
    
}
void names()
{
    glColor3f(0.0,0.0,1.0);
    color(400,950,"BRESENHAM'S LINE DRAWING ALGORITHM");
    glColor3f(0.0,0.5,1.0);
    color(800,100,"Riya Agrahari");
    glColor3f(1.0,0.0,1.0);
    color(800,75,"Mansi Sethi");
    glColor3f(0.0,1.0,0.0);
    color(800,50,"Harshit Mehendritta");
    
}
void mouse(int button, int state, int x, int y)
{

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && counter == 0) {
        x1 = x;
        y1 = 1000-y;
       char buffer[10]={'\0'};
        sprintf(buffer, "%d , %d",x1,y1);
         glRasterPos2f(x1+5,y1+5);
       int length=strlen(buffer);
        for(int i=0 ; i<length ; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,buffer[i]);
            }
       
        counter++;
    }
 
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && counter == 1) {
        x2 = x;
        y2 = 1000-y;
        char buffer[10]={'\0'};
        sprintf(buffer, "%d , %d",x1,y1);
         glRasterPos2f(x1+5,y1+5);
       int length=strlen(buffer);
        for(int i=0 ; i<length ; i++)
            {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,buffer[i]);
            }
        counter--;
       Bresenham((int)x1,(int)y1,(int)x2,(int)y2);

    }
     if(button == GLUT_RIGHT_BUTTON && state== GLUT_DOWN)
     {
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
    }
}





void display()
{
    names();
    glFlush();
    glutPostRedisplay();
}

void init() {
 

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0.0,0.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0,1000.0);
    glutPostRedisplay();
    glFlush();


}

void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: 
        exit(0);
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
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Graphics Assignment 1");
    glutDisplayFunc(display);
	 glutKeyboardFunc(keyInput);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}




	

