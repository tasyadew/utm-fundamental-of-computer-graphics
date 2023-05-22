// DDA
// Prepared by Safia Zulaikha Binti Zulhazmi (A20EC0140)

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

void lineDDA(int x1, int y1, int x2, int y2)
{
	float steps, x, y, xIncrement, yIncrement;

	steps = abs(x2 - x1);

	//To determine whether there will be x increment or y increment
	if (abs(y2 - y1) > steps)
		steps = abs(y2 - y1);

	xIncrement = (x2 - x1) / (steps);
	yIncrement = (y2 - y1) / (steps);

	x = x1;
	y = y1;

	//Each step, it will an intermediate vertex
	for (int i = 0; i < steps; i++)
	{
		setPixel((x + 0.5), (y + 0.5));
		x = x + xIncrement;
		y = y + yIncrement;
	}
}

//Generate pixel
void PlotPixel(float x, float y)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glPointSize(5.0f);

	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

//Draw the line
void drawMyLine()
{

	glClear(GL_COLOR_BUFFER_BIT); //Clears buffer to preset values
	glColor3f(0.0, 1.0, 1.0);
	glPointSize(5.0);
	PlotPixel(1.0, 1.0);
	lineDDA(xStart, yStart, xEnd, yEnd);
}

//Initialising colours
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char** argv)
{
	//Asking user to input start point (x1, y1) and end point (x2, y2)
	cout << "Let's draw a line!\n" << endl;

	cout << "Enter the start point (X1, Y1) => ";
	cin >> xStart >> yStart;

	cout << "\nEnter the end point (X2, Y2) => ";
	cin >> xEnd >> yEnd;


	glutInit(&argc, argv); //Initialise GLUT 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //
	glutInitWindowSize(600, 600); //Set the width and height of the window
	glutInitWindowPosition(50, 50); //Set the position of the window
	glutCreateWindow("DIGITAL DIFFERENTIAL ANALYZER ALGORITHM"); //Display window with the following title
	init(); //Initialise the colours
	glutDisplayFunc(drawMyLine); //Calling drawMyLine() function
	glutMainLoop(); //Enter GLUT's main loop

	return 0;
}