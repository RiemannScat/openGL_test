// openGL_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <vector>

using namespace std;

const float PI = 3.1415265358979323;

const int HEIGHT = 100;
const int WIDTH = 100;

class Point {
public:
	float x, y;
	float r, g, b;

	void show(float k) {
		glColor3f(r,g,b);
		if (k > 1) {
			glVertex2f(2 * x / k, 2 * y);
		}
		else {
			glVertex2f(2 * x, 2 * y * k);
		}
	}

	Point() {
		x = 0.0;
		y = 0.0;
		r = 1.0;
		g = 1.0;
		b = 1.0;
	}

	Point(float x_, float y_) : Point() {
		x = x_;
		y = y_;
	}

	Point(float x_, float y_, float r_, float g_, float b_) : Point(x_, y_) {
		r = r_;
		g = g_;
		b = b_;
	}
};
vector<Point> points;

int dist(int a, int b, int n) {
	int dif = abs(a - b);
	if (dif < (-dif + n)) {
		return dif;
	}
	return -dif + n;
}

void displayCB(void)		/* function called whenever redisplay needed */
{
	glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
	glClearColor(0.01, 0.02, 0.03, 0);
	glPointSize(0.01);
	float k = glutGet(GLUT_WINDOW_WIDTH) / float(glutGet(GLUT_WINDOW_HEIGHT));	
	glBegin(GL_POINTS);
		for (auto point : points) {
			point.show(k);
		}
	glEnd();	
	glFlush();
}

void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
	if (key) exit(0);
}


void createFractal() {
	const int n = 5;
	float percent = 0.5;
	float rotation = -PI / 6;
	Point basePoints[n];
	Point main = Point((rand() % 200 - 100) / 100.0, (rand() % 200 - 100) / 100.0, 0.0, 0.0, 0.0);

	for (int i = 0; i < n; i++) {
		basePoints[i].x = cos(i * 2 * PI / n );
		basePoints[i].y = sin(i * 2 * PI / n );
	}
	points.resize(0);

	int p, prev1 = -1, prev2 = -1, prev3 = -1;	

	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 10000; i++) {

			p = rand() % n;
			if (dist(p, prev1, n) == 0) {
				continue;
			}

			main.x = (basePoints[p].x + main.x) * percent;
			main.y = (basePoints[p].y + main.y) * percent;

			switch (p) {
			case 0:
				main.r = 1.0;
				main.g = 0.0;
				main.b = 0.0;
				break;
			case 1:
				main.r = 0.0;
				main.g = 1.0;				
				main.b = 0.0;
				break;
			case 2:
				main.b = 1.0;
				main.r = 0.0;
				main.g = 0.0;
				break;
			case 3:
				main.r = 1.0;
				main.g = 1.0;
				main.b = 0.0;
				break;
			case 4:
				main.r = 1.0;
				main.g = 0.0784;
				main.b = 0.57647;
				break;
			case 5:
				main.r = 1.0;
				main.g = 0.0;
				main.b = 1.0;
				break;
			default:
				main.r = 1.0;
				main.g = 1.0;
				main.b = 1.0;
			}

			points.push_back(main);

			prev2 = prev1;
			prev1 = p;			
		}
	}


}


int main(int argc, char *argv[])
{

	glutInit(&argc, argv);		/* initialize GLUT system */
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Triangle");	/* create window */
	glutFullScreen();

	/* from this point on the current window is win */

	createFractal();

	glutDisplayFunc(displayCB);		/* set window's display callback */
	glutKeyboardFunc(keyCB);		/* set window's key callback */

	glutMainLoop();			/* start processing events... */

	/* execution never reaches this point */

	return 0;
}


