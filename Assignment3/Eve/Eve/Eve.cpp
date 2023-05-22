#include <GL/glut.h>
#include <windows.h>
#include <math.h>

int w = 640, h = 450;

//define variables for object position
static int vertex = 0, vertex2 = 0, x1 = 0, y2 = 0, z1 = 0, scaleX = 0, scaleY = 0, z = -20;

//to initialize object
void init(void)
{
	//lighting
	glClearColor(45.0 / 255.0, 45.0 / 255.0, 48.0 / 255.0, 0.0);
	GLfloat modelambient[] = { 0, 0.0, 0.0, 0.0 };
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelambient);
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(camX, camY, camZ, 0.0f, 0.0f, 0.0f, upX, upY, upZ);
}

void DrawCircle(float radius) {
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 100.0; i++) {
		float theta = 2.0f * 3.14159265f * float(i) / 100.0;

		float x = radius * cosf(theta);
		float y = radius * sinf(theta);

		glVertex2f(x, y);
	}
	glEnd();
}

//to picture the object
void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -20);

	//head (root)
	glPushMatrix();
	glTranslatef(0, 4.0, 0);
	glRotatef(0.0, 0.0, 1.0, 0.0);

	glScalef(0.6, 0.5, 0.5);
	glColor3f(0.04, 0.01, 0.05);
	glutSolidSphere(4.0, 100, 200);
	glPopMatrix();

	//face 
	glPushMatrix();
	glTranslatef(0, 4.0, 0); //head position
	glRotatef(0.0, 0.0, 1.0, 0.0); //head angle

	glTranslatef(0, -0.25, 0.7);
	glScalef(0.6, 0.5, 0.5);

	glColor3f(-0.9, -0.9, -0.9);
	glutSolidSphere(3.0, 100, 200);
	glPopMatrix();

	//left eye
	glPushMatrix();
	glTranslatef(0, 4.0, 0); //head position
	glRotatef(0.0, 0.0, 1.0, 0.0); //head angle
	glTranslatef(0, -0.25, 0.7); //face position

	glTranslatef(-0.6, -0.4, 0.95);
	glRotatef(70, 0.0, 0.0, 1.0);

	glScalef(1.0, 1.5, 1.5);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	//right eye
	glPushMatrix();
	glTranslatef(0, 4.0, 0); //head position
	glRotatef(0.0, 0.0, 1.0, 0.0); //head angle
	glTranslatef(0, -0.25, 0.7); //face position

	glTranslatef(0.6, -0.4, 0.95);
	glRotatef(110, 0.0, 0.0, 1.0);

	glScalef(1.0, 1.5, 1.5);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	//body
	glPushMatrix();
	glTranslatef(0, 4.0, 0); //head position
	glRotatef(0.0, 0.0, 1.0, 0.0); //head angle

	glTranslatef(0, -6.0, 0);
	glRotatef(0.0, 0.0, 1.0, 0.0);

	glScalef(0.9, 1.25, 0.7);
	glColor3f(0.04, 0.01, 0.05);
	glutSolidSphere(3, 100, 80);

	glRotatef(90, 1.0, 0.0, 0.0);
	glTranslatef(0, 0, -3.0);
	gluCylinder(gluNewQuadric(), 3.0, 3.0, 3.0, 100, 80); //draw cylinder for upper half of body
	DrawCircle(3.0); //to close the cylinder top
	glPopMatrix();

	//left hand
	glPushMatrix();
	glTranslatef(0, 4.0, 0); //head position
	glRotatef(0.0, 0.0, 1.0, 0.0); //head angle
	glTranslatef(0, -6.0, 0); //body position
	glRotatef(0.0, 0.0, 1.0, 0.0); //body angle

	glTranslatef(-3.5, 2.1, 0.0); //hand pivot (shoulder)
	glRotatef(0.0 + 150, 1, 0, 0.0);
	glTranslatef(-0.2, 2.0, 0); //center of hand
	glRotatef(10, 0, 0, 1);  //tilt left

	glScalef(0.2, 1.2, 0.4);
	glColor3f(0.04, 0.01, 0.05);
	glutSolidSphere(3.0, 15, 15);
	glPopMatrix();

	//right hand
	glPushMatrix();
	glTranslatef(0, 4.0, 0); //head position
	glRotatef(0.0, 0.0, 1.0, 0.0); //head angle
	glTranslatef(0, -6.0, 0); //body position
	glRotatef(0.0, 0.0, 1.0, 0.0); //body angle

	glTranslatef(3.5, 2.1, 0.0); //hand pivot (shoulder)
	glRotatef(0.0 + 150, 1, 0, 0.0);
	glTranslatef(0.2, 2.0, 0); //center of hand
	glRotatef(-10, 0, 0, 1);  //tilt right

	glScalef(0.2, 1.2, 0.4);
	glColor3f(0.04, 0.01, 0.05);
	glutSolidSphere(3.0, 15, 15);
	glPopMatrix();

	glutPostRedisplay();
	glutSwapBuffers();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Hello, I am EVE from the movie Wall-E.");
	init();
	glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
	glutMainLoop();
}