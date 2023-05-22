// Fundamental of Computer Graphics - SCSV 2213 
// Assignment 1B- Scene in UTM campus
// Name: Chiam Wooi Chin
// Matric no: A19EC0034
// Section: 01

#include <GL/glut.h> // Include the GLUT header file 
#include <stdlib.h>
#include <math.h>

// set the initial condition function
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Clear the background of our window to white
	glEnable(GL_POINT_SMOOTH); // Enable the points becomes circle
	glMatrixMode(GL_PROJECTION); // Use the Projection Matrix
	gluOrtho2D(0.0, 1600.0, 0.0, 800.0); // Sets up a two-dimensional orthographic viewing region.
}

// set the change size function on glutReshapFunc() reshape function
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the correct perspective.
	gluPerspective(45, ratio, 1, 100);

}

// circle shape function
void circle1(float x, float y, double r) {
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++) {
		float pi = 3.1416;
		float A = (i * pi * 2) / 25;
		float x1 = x + ((r - 0.07) * cos(A));
		float y1 = y + ((r)*sin(A));
		glVertex2f(x1, y1);
	}
	glEnd();
}

// circle shape function
void circle2(float x, float y, double r) {
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 200; i++) {
		float pi = 3.1416;
		float A = (i * pi * 2) / 25;
		float x1 = x + ((r - 0.09) * cos(A));
		float y1 = y + ((r)*sin(A));
		glVertex2f(x1, y1);
	}
	glEnd();
}

void sky() {
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.7, 1.0);// light blue
	glVertex2f(-1.0, 0.2);
	glColor3f(0, 0.501, 1.0);// blue
	glVertex2f(-1.0, 1.0);
	glVertex2f(1.0, 1.0);
	glColor3f(0.5, 0.75, 1.0);// light blue
	glVertex2f(1.0, 0.2);
	glEnd();
}

void field() {
	glBegin(GL_QUADS);
	glColor3f(0.42, 0.57, 0.137);//green
	glVertex2f(-1.0, -1.0);
	glVertex2f(-1.0, 0.2);
	glVertex2f(1.0, 0.2);
	glVertex2f(1.0, -1.0);
	glEnd();
}

void road() {
	// road
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.35, 0.35);// grey
	glVertex2f(0.2, -1.0);
	glColor3f(0.2, 0.2, 0.2);// dark grey
	glVertex2f(1.0, 0.1);
	glVertex2f(1.0, -0.4);
	glColor3f(0.35, 0.35, 0.35);// grey
	glVertex2f(0.70, -1.0);
	glEnd();

	// white strips on the road count from bottom
	// 1st white strip on road
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(0.39, -1.05);
	glVertex2f(0.48, -0.92);
	glVertex2f(0.50, -0.93);
	glVertex2f(0.41, -1.06);
	glEnd();

	// 2nd white strip on road
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(0.54, -0.82);
	glVertex2f(0.63, -0.69);
	glVertex2f(0.65, -0.70);
	glVertex2f(0.56, -0.83);
	glEnd();

	// 3rd white strip on road
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(0.69, -0.59);
	glVertex2f(0.78, -0.46);
	glVertex2f(0.80, -0.47);
	glVertex2f(0.71, -0.60);
	glEnd();

	// 4th white strip on road
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(0.83, -0.37);
	glVertex2f(0.92, -0.24);
	glVertex2f(0.94, -0.25);
	glVertex2f(0.85, -0.38);
	glEnd();

	// 5th white strip on road
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(0.98, -0.14);
	glVertex2f(1.07, -0.01);
	glVertex2f(1.08, -0.02);
	glVertex2f(1.00, -0.15);
	glEnd();
}

void hill() {
	// 1st hill at middle
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.5, 0.0);// brown
	glVertex2f(-0.20, 0.20);
	glColor3f(0.3, 0.3, 0.0);//dark brown
	glVertex2f(0.03, 0.50);
	glVertex2f(0.20, 0.20);

	// 2nd hill at right side
	glColor3f(0.5, 0.5, 0.0);// brown
	glVertex2f(-0.05, 0.20);
	glColor3f(0.3, 0.3, 0.0);//dark brown
	glVertex2f(-0.35, 0.45);
	glVertex2f(-0.60, 0.20);

	// 3rd hill at right-end
	glColor3f(0.5, 0.5, 0.0);// brown
	glVertex2f(-0.90, 0.20);
	glColor3f(0.3, 0.3, 0.0);//dark brown
	glVertex2f(-0.65, 0.30);
	glVertex2f(-0.50, 0.20);

	// 4th hill at left side
	glColor3f(0.5, 0.5, 0.0);// brown
	glVertex2f(0.55, 0.20);
	glColor3f(0.3, 0.3, 0.0);//dark brown
	glVertex2f(0.35, 0.45);
	glVertex2f(0.10, 0.20);

	// 5th hill at left side
	glColor3f(0.5, 0.5, 0.0);// brown
	glVertex2f(0.80, 0.20);
	glColor3f(0.3, 0.3, 0.0);//dark brown
	glVertex2f(0.67, 0.40);
	glVertex2f(0.43, 0.20);

	// 6th hill at left-end
	glColor3f(0.3, 0.3, 0.0);//dark brown
	glVertex2f(1.3, 0.20);
	glVertex2f(0.90, 0.40);
	glColor3f(0.5, 0.5, 0.0);// brown
	glVertex2f(0.70, 0.20);

	glEnd();
}

void sun() {
	glColor3f(1.000, 0.5, 0.05);// orange
	circle1(0.75, 0.75, 0.18);
}

void cloud1() {
	glColor3f(0.8, 0.9, 1.0); // light blue
	circle1(-0.85, 0.77, 0.15);
	circle1(-0.79, 0.70, 0.15);
	circle1(-0.70, 0.70, 0.15);
	circle1(-0.75, 0.77, 0.15);
}

void cloud2() {
	glColor3f(0.8, 0.9, 1.0); // light blue
	circle2(-0.05, 0.77, 0.15);
	circle1(-0.15, 0.70, 0.15);
	circle2(-0.25, 0.75, 0.15);
	circle1(-0.15, 0.80, 0.15);
}

// 1st tree at right side
void tree1() {
	// green leaves on tree
	glColor3f(0.0, 0.5, 0.0);//green
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.8, 0.15);
	glVertex2f(-0.85, 0.05);
	glVertex2f(-0.75, 0.05);

	glVertex2f(-0.8, 0.1);
	glVertex2f(-0.86, 0.0);
	glVertex2f(-0.74, 0.0);

	glVertex2f(-0.8, 0.05);
	glVertex2f(-0.88, -0.05);
	glVertex2f(-0.72, -0.05);

	glEnd();

	// trunk of tree
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.2, 0.0);//dark brown
	glVertex2f(-0.81, -0.1);
	glVertex2f(-0.81, -0.05);
	glVertex2f(-0.79, -0.05);
	glVertex2f(-0.79, -0.1);
	glEnd();

}

// 2nd tree at right side
void tree2() {
	// green leaves on tree
	glColor3f(0.0, 0.5, 0.0);//green
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5, 0.25);
	glVertex2f(-0.55, 0.15);
	glVertex2f(-0.45, 0.15);

	glVertex2f(-0.5, 0.2);
	glVertex2f(-0.56, 0.1);
	glVertex2f(-0.44, 0.1);

	glVertex2f(-0.5, 0.15);
	glVertex2f(-0.58, 0.05);
	glVertex2f(-0.42, 0.05);

	glEnd();

	// trunk of tree
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.2, 0.0);//dark brown
	glVertex2f(-0.51, 0.05);
	glVertex2f(-0.51, 0.0);
	glVertex2f(-0.49, 0.0);
	glVertex2f(-0.49, 0.05);
	glEnd();

}

// 3rd tree at left side
void tree3() {
	// green leaves on tree
	glColor3f(0.0, 0.5, 0.0);//green
	glBegin(GL_TRIANGLES);
	glVertex2f(0.1, 0.3);
	glVertex2f(0.05, 0.2);
	glVertex2f(0.15, 0.2);

	glVertex2f(0.1, 0.25);
	glVertex2f(0.04, 0.15);
	glVertex2f(0.16, 0.15);

	glVertex2f(0.1, 0.2);
	glVertex2f(0.02, 0.1);
	glVertex2f(0.18, 0.1);

	glEnd();

	// trunk of tree
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.2, 0.0);//dark brown
	glVertex2f(0.11, 0.1);
	glVertex2f(0.11, 0.05);
	glVertex2f(0.09, 0.05);
	glVertex2f(0.09, 0.1);
	glEnd();

}

// 4th tree at left side
void tree4() {
	// green leaves on tree
	glColor3f(0.0, 0.5, 0.0);//green
	glBegin(GL_TRIANGLES);
	glVertex2f(0.4, 0.2);
	glVertex2f(0.3, 0.05);
	glVertex2f(0.5, 0.05);

	glVertex2f(0.4, 0.125);
	glVertex2f(0.28, -0.025);
	glVertex2f(0.52, -0.025);

	glVertex2f(0.4, 0.05);
	glVertex2f(0.25, -0.1);
	glVertex2f(0.55, -0.1);

	glEnd();

	// trunk of tree
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.2, 0.0);//dark brown
	glVertex2f(0.42, -0.1);
	glVertex2f(0.42, -0.2);
	glVertex2f(0.38, -0.2);
	glVertex2f(0.38, -0.1);
	glEnd();

}

// 2nd tree beside the buidling
void tree5() {
	// green leaves on tree
	glColor3f(0.0, 0.5, 0.0);//green
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.8, -0.15);
	glVertex2f(-0.95, -0.35);
	glVertex2f(-0.65, -0.35);

	glVertex2f(-0.8, -0.25);
	glVertex2f(-0.97, -0.45);
	glVertex2f(-0.63, -0.45);

	glVertex2f(-0.8, -0.35);
	glVertex2f(-1.0, -0.55);
	glVertex2f(-0.60, -0.55);

	glEnd();

	// trunk of tree
	glBegin(GL_QUADS);
	glColor3f(0.35, 0.2, 0.0);//dark brown
	glVertex2f(-0.83, -0.55);
	glVertex2f(-0.83, -0.75);
	glVertex2f(-0.77, -0.75);
	glVertex2f(-0.77, -0.55);
	glEnd();

}

// the UTM campus building
void building() {
	//WALL
	// wall-first floor
	glColor3f(1.0, 0.8, 0.5);//Beige
	glBegin(GL_QUADS);
	glVertex2f(0.15, -0.5);
	glVertex2f(-0.55, -0.5);
	glVertex2f(-0.55, -0.2);
	glVertex2f(0.15, -0.2);
	glEnd();

	// wall-first floor (side)
	glColor3f(0.95, 0.7, 0.4);//Beige
	glBegin(GL_QUADS);
	glVertex2f(0.18, -0.17);
	glVertex2f(0.18, -0.47);
	glVertex2f(0.15, -0.5);
	glVertex2f(0.15, -0.2);
	glEnd();

	// wall- ground floor
	glColor3f(1.0, 0.8, 0.5);//Beige
	glBegin(GL_QUADS);
	glVertex2f(0.15, -0.85);
	glVertex2f(-0.57, -0.85);
	glVertex2f(-0.57, -0.5);
	glVertex2f(0.15, -0.5);
	glEnd();

	// wall- ground floor (side)
	glColor3f(0.95, 0.7, 0.4);//Beige
	glBegin(GL_QUADS);
	glVertex2f(0.18, -0.47);
	glVertex2f(0.18, -0.82);
	glVertex2f(0.15, -0.85);
	glVertex2f(0.15, -0.5);
	glEnd();


	//ROOF
	//roof-top
	glColor3f(0.2, 0.1, 0.0);// dark brown
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.2, 0.05);
	glColor3f(0.4, 0.2, 0.0); // brown
	glVertex2f(-0.63, -0.2);
	glVertex2f(0.23, -0.2);
	glEnd();

	// roof-bottom 
	glColor3f(0.2, 0.1, 0.0);// dark brown
	glBegin(GL_QUADS);
	glVertex2f(0.15, -0.5);
	glVertex2f(0.17, -0.55);
	glVertex2f(-0.60, -0.55);
	glVertex2f(-0.57, -0.5);
	glEnd();

	// roof-bottom (side)
	glBegin(GL_QUADS);
	glVertex2f(0.18, -0.45);
	glVertex2f(0.21, -0.48);
	glVertex2f(0.17, -0.55);
	glVertex2f(0.15, -0.5);
	glEnd();


	//WINDOW 
	//window - first floor (left)
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.80, 0.80);// grey
	glVertex2f(-0.33, -0.25);
	glVertex2f(-0.33, -0.45);
	glVertex2f(-0.50, -0.45);
	glVertex2f(-0.50, -0.25);
	glEnd();

	// left window (right part)
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.34, -0.27);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.34, -0.43);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.41, -0.43);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.41, -0.27);
	glEnd();

	// left window (left part)
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.42, -0.27);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.42, -0.43);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.49, -0.43);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.49, -0.27);
	glEnd();

	// lines on left window (right part)
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(-0.34, -0.31);
	glVertex2f(-0.41, -0.31);
	glVertex2f(-0.375, -0.43);
	glVertex2f(-0.375, -0.27);
	glEnd();

	// lines on left window (left part)
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(-0.42, -0.31);
	glVertex2f(-0.49, -0.31);
	glVertex2f(-0.455, -0.43);
	glVertex2f(-0.455, -0.27);
	glEnd();

	//window - first floor (middle)
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_QUADS);
	glVertex2f(-0.13, -0.25);
	glVertex2f(-0.13, -0.45);
	glVertex2f(-0.28, -0.45);
	glVertex2f(-0.28, -0.25);
	glEnd();

	// middle window - right part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.14, -0.27);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.14, -0.43);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.20, -0.43);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.20, -0.27);
	glEnd();

	// middle window - left part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.21, -0.27);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.21, -0.43);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.27, -0.43);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.27, -0.27);
	glEnd();

	// lines on middle window right part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(-0.14, -0.31);
	glVertex2f(-0.20, -0.31);
	glVertex2f(-0.17, -0.43);
	glVertex2f(-0.17, -0.27);
	glEnd();

	// lines on middle window left part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(-0.21, -0.31);
	glVertex2f(-0.27, -0.31);
	glVertex2f(-0.24, -0.43);
	glVertex2f(-0.24, -0.27);
	glEnd();

	//window - first floor (right)
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_QUADS);
	glVertex2f(0.1, -0.25);
	glVertex2f(0.1, -0.45);
	glVertex2f(-0.08, -0.45);
	glVertex2f(-0.08, -0.25);
	glEnd();

	// right window -right part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(0.09, -0.27);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(0.09, -0.43);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(0.015, -0.43);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(0.015, -0.27);
	glEnd();

	// right window- left part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(0.005, -0.27);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(0.005, -0.43);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.07, -0.43);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.07, -0.27);
	glEnd();

	// lines on right window right part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(0.09, -0.31);
	glVertex2f(0.015, -0.31);
	glVertex2f(0.05, -0.43);
	glVertex2f(0.05, -0.27);
	glEnd();

	// lines on right window left part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(0.005, -0.31);
	glVertex2f(-0.07, -0.31);
	glVertex2f(-0.035, -0.43);
	glVertex2f(-0.035, -0.27);
	glEnd();

	//window - ground floor (left)
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_QUADS);
	glVertex2f(-0.35, -0.60);
	glVertex2f(-0.35, -0.75);
	glVertex2f(-0.50, -0.75);
	glVertex2f(-0.50, -0.60);
	glEnd();

	// left window right part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.36, -0.62);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.36, -0.73);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.42, -0.73);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.42, -0.62);
	glEnd();

	// left window left part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.43, -0.62);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.43, -0.73);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.49, -0.73);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.49, -0.62);
	glEnd();

	// lines on left window right part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(-0.36, -0.675);
	glVertex2f(-0.42, -0.675);
	glVertex2f(-0.39, -0.73);
	glVertex2f(-0.39, -0.62);
	glEnd();

	// lines on left window left part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(-0.43, -0.675);
	glVertex2f(-0.49, -0.675);
	glVertex2f(-0.46, -0.73);
	glVertex2f(-0.46, -0.62);
	glEnd();

	//window - ground floor (right)
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.80, 0.80);// grey
	glVertex2f(-0.05, -0.60);
	glVertex2f(-0.05, -0.75);
	glVertex2f(0.10, -0.75);
	glVertex2f(0.10, -0.60);
	glEnd();

	// right window - right part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(0.09, -0.62);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(0.09, -0.73);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(0.03, -0.73);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(0.03, -0.62);
	glEnd();

	// right window - left part
	glBegin(GL_QUADS);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(0.02, -0.62);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(0.02, -0.73);
	glColor3f(0.7, 1.0, 1.0);// light blue
	glVertex2f(-0.04, -0.73);
	glColor3f(1.0, 1.0, 1.0);// white
	glVertex2f(-0.04, -0.62);
	glEnd();

	// lines on right window right part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(0.09, -0.675);
	glVertex2f(0.03, -0.675);
	glVertex2f(0.06, -0.73);
	glVertex2f(0.06, -0.62);
	glEnd();

	// lines on right window left part
	glColor3f(0.8, 0.80, 0.80);// grey
	glBegin(GL_LINES);
	glVertex2f(0.02, -0.675);
	glVertex2f(-0.04, -0.675);
	glVertex2f(-0.01, -0.73);
	glVertex2f(-0.01, -0.62);
	glEnd();

	//door (ground floor)
	glBegin(GL_QUADS);
	glColor3f(0.70, 0.2, 0.0);//Brown
	glVertex2f(-0.3, -0.85);
	glColor3f(0.4, 0.1, 0.0);//Dark Brown
	glVertex2f(-0.3, -0.65);
	glVertex2f(-0.1, -0.65);
	glColor3f(0.70, 0.2, 0.0);//Brown
	glVertex2f(-0.1, -0.85);
	glEnd();

	// lines on door
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);//Black
	glVertex2f(-0.2, -0.85);
	glVertex2f(-0.2, -0.65);
	glEnd();

	// circle points on door
	glColor3f(0.0f, 0.0f, 0.0f);//Black
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(-0.18, -0.75);
	glVertex2f(-0.22, -0.75);
	glEnd();

}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clear the colour buffer and depth buffer
	glColor3d(1, 0, 0);
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations 
	glMatrixMode(GL_MODELVIEW); // Use the Modelview Matrix

	// call the function of the objects
	sky();
	field();
	road();
	hill();
	sun();
	cloud1();
	cloud2();
	tree1();
	tree2();
	tree3();
	tree4();
	tree5();
	building();

	glFlush(); // Flush the OpenGL buffers to the window 
	glutSwapBuffers();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initialize GLUT 
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1000, 600); // Set the width and height of the window 
	glutInitWindowPosition(50, 50); // Set the position of the window 
	glutCreateWindow("Scene in UTM Campus"); // Set the title for the window 

	init();// call the initial condition function
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering 
	glutReshapeFunc(changeSize);
	glutMainLoop(); // Enter GLUT's main loop 

	return 0;
}