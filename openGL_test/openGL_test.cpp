// openGL_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <GL/glut.h>

using namespace std;

const float PI = 3.1415265358979323;

void displayCB(void)		/* function called whenever redisplay needed */
{
	glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
	glClearColor(0.0, 0.0, 0.0, 0);
	glColor3f(1.0, 1.0, 1.0);

	float ax, ay, bx, by, cx, cy, dx,dy,ex,ey;
	float x, y;

	glPointSize(0.1);
	glBegin(GL_POINTS);

	int n = 5;

	ax = cos(2 * PI / n);
	ay = sin(2 * PI / n);

	bx = cos(2*2 * PI / n);
	by = sin(2*2 * PI / n);

	cx = cos(3 * 2 * PI / n);
	cy = sin(3 * 2 * PI / n);

	dx = cos(4 * 2 * PI / n);
	dy = sin(4 * 2 * PI / n);

	ex = cos(5 * 2 * PI / n);
	ey = sin(5 * 2 * PI / n);

	x = (rand() % 200 - 100) / 100.0;
	y = (rand() % 200 - 100) / 100.0;

	int p, prev = -1;

	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 10000; i++) {
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(x, y);

			p = rand() % n;
			if (p == prev) {
				continue;
			}

			if (p == 0) {
				x = (ax + x) * 0.5;
				y = (ay + y) * 0.5;
			}
			else if (p == 1) {
				x = (bx + x) * 0.5;
				y = (by + y) * 0.5;
			}
			else if (p == 2) {
				x = (cx + x) * 0.5;
				y = (cy + y) * 0.5;
			}
			else if (p == 3) {
				x = (dx + x) * 0.5;
				y = (dy + y) * 0.5;
			}
			else if (p == 4) {
				x = (ex + x) * 0.5;
				y = (ey + y) * 0.5;
			}

			prev = p;
		}
	}
	glEnd();	
	glFlush();
}

void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
	if (key) exit(0);
}

int main(int argc, char *argv[])
{

	glutInit(&argc, argv);		/* initialize GLUT system */
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);		/* width=400pixels height=500pixels */
	glutCreateWindow("Triangle");	/* create window */

	/* from this point on the current window is win */

	glutDisplayFunc(displayCB);		/* set window's display callback */
	glutKeyboardFunc(keyCB);		/* set window's key callback */

	glutMainLoop();			/* start processing events... */

	/* execution never reaches this point */

	return 0;
}


