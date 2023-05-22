#include <Windows.h>
#include <GL/glut.h>	

static int window;
static int menu_id;
static int submenu_id;
static int value;// = 2;

void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	}
	else {
		value = num;
	}
	glutPostRedisplay();
}

void createMenu(void) {
	submenu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Cube", 2);
	glutAddMenuEntry("Cone", 3);
	glutAddMenuEntry("Torus", 4);
	glutAddMenuEntry("Teapot", 5);

	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Clear", 1);
	glutAddSubMenu("Draw", submenu_id);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void input(void) {

}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	if (value == 1) {
		glutPostRedisplay();
	}
	else if (value == 2) {
		glPushMatrix();
		glColor3d(1.0, 0.0, 0.0);
		//glTranslated(-0.5, -0.5, 0.0);
		glRotatef(25.0, 1.0, -1.0, 0.05);
		glutWireCube(1.0);
		glPopMatrix();
	}
	else if (value == 3) {
		glPushMatrix();
		glColor3d(0.0, 1.0, 0.0);

		glPopMatrix();
	}
	else if (value == 4) {
		glPushMatrix();
		glColor3d(0.0, 0.0, 1.0);

		glPopMatrix();
	}
	else if (value == 5) {
		glPushMatrix();
		glColor3d(1.0, 0.0, 1.0);

		glPopMatrix();
	}
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("3D Objects from GLUT Library");

	createMenu();

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}