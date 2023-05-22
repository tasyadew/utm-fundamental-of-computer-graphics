#include <GL/glut.h> // Include the GLUT header file 
void init(void) {
	glClearColor(0.39f, 0.78f, 0.39f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 1.0, 1.0);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initialize GLUT 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Your first OpenGL Window");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}