// openGL_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <GL/glut.h>

using namespace std;

void displayCB(void)		/* function called whenever redisplay needed */
{
	glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(1.0, 0.5, 0.11);

	glBegin(GL_LINE_LOOP);
		glVertex2i(100, 100);
		glVertex2i(200, 100);
		glVertex2i(200, 200);
		glVertex2i(100, 200);
	glEnd();

	glFlush();				/* Complete any pending operations */
}

void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
	if (key == 'q') exit(0);
}

int main(int argc, char *argv[])
{

	glutInit(&argc, argv);		/* initialize GLUT system */

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);		/* width=400pixels height=500pixels */
	glutCreateWindow("Triangle");	/* create window */

	gluOrtho2D(100, 700, 700, 100);

	/* from this point on the current window is win */

	glutDisplayFunc(displayCB);		/* set window's display callback */
	glutKeyboardFunc(keyCB);		/* set window's key callback */

	glutMainLoop();			/* start processing events... */

	/* execution never reaches this point */

	return 0;
}


