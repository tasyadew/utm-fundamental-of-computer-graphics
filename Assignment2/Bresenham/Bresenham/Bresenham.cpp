#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

float xStart, yStart, xEnd, yEnd;

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	//Plotting the points
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush(); //Flush the OpenGL buffers to the window
}

void lineBresenham(int x0, int y0, int xEnd, int yEnd)
{
	float pk, k; //dx, dy, xIncrement=1, yIncrement=1;
	float dx = xEnd - x0;
	float dy = yEnd - y0;
	float dx2 = 2 * dx;
	float dy2 = 2 * dy;
	float dydx2 = dy2 - dx2;
	float xIncrement = 1, yIncrement = 1, x = x0, y = y0;
	pk = dy2 - dx;
	//To determine whether there will be x increment or y increment
	for (k = 0; k < dx; k++)
		if (pk < 0) {
			pk = pk + dy2;
			x += xIncrement;
			setPixel(round(x), round(y));
		}
		else {
			pk = pk + dydx2;
			x += xIncrement;
			y += yIncrement;
			setPixel(round(x), round(y));
		}
}

void PlotPixel(float x, float y)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glPointSize(5.0f);

	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void drawMyLine()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glPointSize(5.0);
	PlotPixel(1.0, 1.0);
	lineBresenham(xStart, yStart, xEnd, yEnd);
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char** argv)
{
	//Asking user to input start point (x1, y1) and end point (x2, y2)
	cout << "Enter start and end points to draw a line" << endl;

	cout << "Enter the start point p1(x1, y1) and end point p2(x2, y2) ";
	cin >> xStart >> yStart >> xEnd >> yEnd;


	glutInit(&argc, argv); //Initialise GLUT 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //
	glutInitWindowSize(600, 600); //Set the width and height of the window
	glutInitWindowPosition(50, 50); //Set the position of the window
	glutCreateWindow("BRENSENHAM ALGORITHM"); //Display window with the following title
	init(); //Initialise the colours
	glutDisplayFunc(drawMyLine); //Calling drawMyLine() function
	glutMainLoop(); //Enter GLUT's main loop

	return 0;
}