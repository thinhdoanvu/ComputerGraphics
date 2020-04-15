#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void display()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	   
	 glColor3f(1,0,0);
	 glBegin(GL_POLYGON);
	 glVertex2f(100,300);
	 glVertex2f(100,100);
	 glVertex2f(200,100);
	 glVertex2f(200,300);
	 glEnd();
	   
	 glFlush();
	 glutSwapBuffers();
}

int main(int argc, char** argv)
{ 
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	 glutInitWindowSize(640,640);
	 glutCreateWindow("OpenGL");
	 glutDisplayFunc(display);
	 gluOrtho2D(0,640,0,640);
	 glClearColor(0.5,0.7,0.5,0);
	 glutMainLoop();
	 return 0;
}
