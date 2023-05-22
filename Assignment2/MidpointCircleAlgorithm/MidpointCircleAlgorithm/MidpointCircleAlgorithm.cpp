// Midpoint Circle Algorithm
// Prepared by Natasya Nadhira Binti Ahmad Nazrain (A20EC0103)

#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<iomanip>

//set the initial window size
GLint winWidth = 750;
GLint winHeight = 750;

//global variables
int xc, yc; //center point of the circle
int radius = 250; //change the circle radius here !!

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void plotPixel(GLint xCoordinate, GLint yCoordinate) {
	glColor3f(0, 0, 1); // set color to blue
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

class Circle {
	private:
		GLint x, y;
	public:
		// initializes coordinate position to (0, 0)
		Circle() {
			x = 0;
			y = 0;
		}

		void setCoords(GLint xPos, GLint yPos) {
			x = xPos;
			y = yPos;
		}

		GLint getx() const { return x; }
		GLint gety() const { return y; }
		void incrementx() { x++; }
		void decrementy() { y--; }
};

void plotCirclePoint(GLint xc, GLint yc, Circle c) {
	plotPixel(xc + c.getx(), yc + c.gety());
	plotPixel(xc - c.getx(), yc + c.gety());
	plotPixel(xc + c.getx(), yc - c.gety());
	plotPixel(xc - c.getx(), yc - c.gety());
	plotPixel(xc + c.gety(), yc + c.getx());
	plotPixel(xc - c.gety(), yc + c.getx());
	plotPixel(xc + c.gety(), yc - c.getx());
	plotPixel(xc - c.gety(), yc - c.getx());
}

void midpointCircleAlgorithm(GLint xc, GLint yc, GLint radius) {
	Circle c;
	GLint p = 1 - radius; // Initial value for midpoint parameter.
	c.setCoords(0, radius); // Set coordinates for top point of circle.
	plotCirclePoint(xc, yc, c); // Plot the initial point in each circle quadrant. 
	
	// Calculate next point and plot in each octant. 
	while (c.getx() < c.gety()) {
		c.incrementx();
		if (p < 0)
			p += 2 * c.getx() + 1;
		else {
			c.decrementy();
			p += 2 * (c.getx() - c.gety()) + 1;
		}
		plotCirclePoint(xc, yc, c);
	}
}

//function to display text
void text(float x, float y, void* font, char* string) {
	char* c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
		glutBitmapCharacter(font, *c); //char datatype can fit into int datatype (implicit conversion)
		x1 = x1 + glutBitmapWidth(font, *c);
	}
}

//function to display about the program text using text function
void infoText() {
	//text array
	char t1[] = "About this program:";
	char t2[] = "Left click anywhere to initialize ";
	char t3[] = "the center point of a circle.";
	char t4[] = "It will then generate a circle ";
	char buffer[50];
	sprintf_s(buffer, "with radius of %d", radius);

	//draw text
	int x_pos = 10;
	int y_pos = winHeight - 10;
	glColor3f(0, 0, 0);
	text(x_pos, y_pos - 30, GLUT_BITMAP_8_BY_13, t1);
	text(x_pos, y_pos - 60, GLUT_BITMAP_8_BY_13, t2);
	text(x_pos, y_pos - 80, GLUT_BITMAP_8_BY_13, t3);
	text(x_pos, y_pos - 100, GLUT_BITMAP_8_BY_13, t4);
	text(x_pos, y_pos - 120, GLUT_BITMAP_8_BY_13, buffer);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	infoText();
	glFlush();
}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xc = x;
		yc = winHeight-y;
		midpointCircleAlgorithm(xc, yc, radius); //will draw circle if click
	}
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Midpoint Circle Algorithm");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(myMouse);
	glutMainLoop();
}