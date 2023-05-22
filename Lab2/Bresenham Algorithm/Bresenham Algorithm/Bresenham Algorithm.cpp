#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

inline GLint round(const GLfloat a) { return GLint(a + 0.5); }

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

/* Bresenham line-drawing procedure for |m| < 1.0. */
void lineBres(int x0, int y0, int xEnd, int yEnd)
{
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	/* Determine which endpoint to use as start position. */
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else {
		x = x0;
		y = y0;
	}
	setPixel(x, y);
	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}
		setPixel(x, y);
	}
}

void drawMyLine(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(4.0);
	GLint x0 = 100;
	GLint y0 = 100;
	GLint xEnd = 200;
	GLint yEnd = 200;
	lineBres(x0, y0, xEnd, yEnd);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Brensenham's Line Algorithm");
	init();
	glutDisplayFunc(drawMyLine);
	glutMainLoop();
}