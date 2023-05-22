#include <windows.h>
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
	sprintf_s(buf, "TEST MY AUDIO");
	renderBitmap(10, 370, GLUT_BITMAP_TIMES_ROMAN_24, buf);
	sprintf_s(buf, "==============");
	renderBitmap(10, 350, GLUT_BITMAP_TIMES_ROMAN_24, buf);

	glColor3f(1, 1, 1);
	sprintf_s(buf, "AUDIO TITLE : Castle by Lukrembo");
	renderBitmap(10, 320, GLUT_BITMAP_HELVETICA_18, buf);
	sprintf_s(buf, "AUDIO FORMAT : WAV");
	renderBitmap(10, 280, GLUT_BITMAP_HELVETICA_18, buf);
	sprintf_s(buf, "DURATION : 180 seconds");
	renderBitmap(10, 240, GLUT_BITMAP_HELVETICA_18, buf);

	glColor3f(1, 1, 1);
	sprintf_s(buf, "Press [A] to play an audio.");
	renderBitmap(10, 140, GLUT_BITMAP_HELVETICA_18, buf);
	sprintf_s(buf, "Press [S] to stop playing audio.");
	renderBitmap(10, 120, GLUT_BITMAP_HELVETICA_18, buf);
}

void display()
{
	displayTexts();
	glFlush();
}

static void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'a':
		case 'A':
			PlaySoundA("C:\\Users\\Natasya\\Music\\lukrembo_castle.wav", NULL, SND_ASYNC);
			break;

		case 's':
		case 'S':
			PlaySound(NULL, 0, 0);
			break;
	}
	glFlush();
	glutPostRedisplay();
}

int main(int arg, char** argv)
{
	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Playing AUDIO!");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}