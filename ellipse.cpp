#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.141593
float cx,cy,a,b,x,y;
void draw(float cx, float cy, float x, float y)
{
    glBegin(GL_POINTS);
    glPointSize(5.0);
    glVertex2f(cx+x,cy+y);
    glVertex2f(cx-x,cy+y);
    glVertex2f(cx+x,cy-y);
    glVertex2f(cx-x,cy-y);
    glEnd();
}
void ellipse()
{
 
    float x = 0, y = b, p;
    float px = 0, py = 2 * a*a * y;
 
    draw(cx, cy, x, y);
    p = b*b - (a*a * b) + (0.25 * a*a);
    while (px < py)
    {
        x++;
        px = px + 2 * b*b;
        if (p < 0)
            p = p + b*b + px;
        else
        {
            y--;
            py = py - 2 * a*a;
            p = p + b*b + px - py;
        }
        draw(cx, cy, x, y);
    }

    p = b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) - a*a*b*b;
    while (y > 0)
    {
        y--;
        py = py - 2 * a*a;
        if (p > 0)
            p = p + a*a - py;
        else
        {
            x++;
            px = px + 2 * b*b;
            p = p + a*a - py + px;
        }
        draw(cx, cy, x, y);

    }
}
void myDisplay(void)
{
    ellipse();
    glFlush ();
}
void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}
int main(int argc, char **argv)
 {
    printf("Enter position of center xc , yc");
    scanf("%f %f",&cx,&cy);
    printf("Enter value of a,b\n");
     scanf("%f %f",&a,&b);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Ellipse Generation using midpoint");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
