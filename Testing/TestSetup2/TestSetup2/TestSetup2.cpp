#include <Windows.h>
#include <GL/gl.h> // Include the GL header file 
#include <GL/glu.h>
#include <GL/glut.h> // Include the GLUT header file 

void init(void)
{
	glClearColor(0.92f, 0.66f, 0.75f, 1.0f); // Clear the background of our window to pink 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0); //left, right, bottom, top
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on) 
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations 
	glColor3f(1.0, 1.0, 1.0); //color for the output primitive

	glFlush(); // Flush the OpenGL buffers to the window 
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initialize GLUT 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up a basic display buffer (only single 
	// buffered for now) 
	glutInitWindowSize(480, 853); // Set the width and height of the window 
	glutInitWindowPosition(600, 100); // Set the position of the window 
	glutCreateWindow("Your first OpenGL Window"); // Set the title for the window 
	init();
	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering 

	glutMainLoop(); // Enter GLUT's main loop 

}