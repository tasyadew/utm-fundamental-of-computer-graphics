#include <GL/glut.h> // Include the GLUT header file
#include <GL/GLU.h>
#include <GL/GL.h>
#include <cmath>

void init(void) {
	glClearColor(0.92, 0.66, 0.75, 1.0);
	//gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
	//glFrustum(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// gluPerspective for 3D view. gluOrtho2D for 2D view.
	// gluOrtho2D is actually gluOrtho with default near = -1 and far = 1
	// glOrtho - close and far appears same size
	// gluFrustum - far looks small, close looks bigger
	// refer: https://stackoverflow.com/questions/2571402/how-to-use-glortho-in-opengl
	// Set the correct perspective.
	gluPerspective(100, ratio, 10, 10);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

/*
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
	glColor3f(1.0, 1.0, 1.0); //color for the output primitive
	glPointSize(3.0);

	//refer: https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glBegin.xml
	glBegin(GL_POLYGON);
	glVertex3f(-1, -1, -2.0);
	glVertex3f(1, 0.0, -2.0);
	glVertex3f(1, 1.0, -2.0);
	glEnd();

	glutSwapBuffers();

}
*/

/*
void triangle_shape(float x_center, float y_center, float r, float n) {
	glBegin(GL_POLYGON);
	float a = (2 * 3.142) / n;
	int i = 0;

	while (i < n) {
		float x = x_center + r * cos(i * a);
		float y = y_center + r * sin(i * a);

		glVertex2d(x, y);
		i += 1;
	}
	glEnd();
}
*/

//refer: https://bloggrammings.blogspot.com/2020/03/membuat-heart-shape-dengan-menggunakan.html
void heart_shape(float x_center, float y_center, float r, float n) {

	glBegin(GL_POLYGON);
	float a = (2 * 3.142) / n;
	int i = 0;

	while (i < n) {
		float x = x_center + r * (16 * (pow(sin(i * a), 3)));
		float y = y_center + r * (13 * cos(i * a) - 5 * cos(2 * i * a) - 2 * cos(3 * i * a) - cos(4 * i * a));

		glVertex2d(x, y);
		i += 1;
	}
	glEnd();
}

void plotpoints(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.89, 0.38, 0.53);
	glPointSize(13);
	/*
	//display XY axis
	glBegin(GL_LINES);
		glVertex2f(-500, 0);
		glVertex2f(500, 0);
		glVertex2f(0, -500);
		glVertex2f(0, 500);
	glEnd();
	*/

	//triangle_shape(0, 0, 300, 3);


	heart_shape(0, 50, 13, 100); //(x, y, size, poly)
	glFlush();

}



int main(int argc, char** argv) {
	// init GLUT and create window
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Pink Heart - This was harder than I thought");

	// register callbacks
	//glutDisplayFunc(display);
	glutDisplayFunc(plotpoints);
	glutReshapeFunc(changeSize);

	// enter GLUT event processing loop
	init();
	glutMainLoop();

	return 1;
}