#include <Windows.h>
#include <GL/glut.h>
#include <fstream>

int width = 600;
int height = 400;

void init()
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GLUT_SINGLE | GLUT_RGB);
	glLoadIdentity();
	glOrtho(0, width, 0, height, 0.0, 1.0);
}

void renderBitmap(float x, float y, void* font, char* string)
{
	char* c;

	glRasterPos2f(x, y);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void displayTexts()
{
	char buf[100] = { 0 };

	glColor3f(1, 1, 1);
	sprintf_s(buf, "MY CONTACT INFO");
	renderBitmap(10, 370, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "================");
	renderBitmap(10, 350, GLUT_BITMAP_TIMES_ROMAN_24, buf);

	glColor3f(0, 1, 0);
	sprintf_s(buf, "NAME : MUHAMAD NAJIB BIN ZAMRI");
	renderBitmap(10, 320, GLUT_BITMAP_HELVETICA_18, buf);
	sprintf_s(buf, "ADDRESS : Taman Pulai Utama, Skudai, Johor.");
	renderBitmap(10, 280, GLUT_BITMAP_HELVETICA_18, buf);
	sprintf_s(buf, "PHONE : +6012-4579063");
	renderBitmap(10, 240, GLUT_BITMAP_HELVETICA_18, buf);
	sprintf_s(buf, "EMAIL : najibzamri@gmail.com");
	renderBitmap(10, 200, GLUT_BITMAP_HELVETICA_18, buf);
}

void display()
{
	displayTexts();
	glFlush();
}

int main(int arg, char** argv)
{
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Displaying TEXTS!");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}