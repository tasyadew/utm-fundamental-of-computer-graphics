#include <Windows.h>
#include <GL/glut.h>
#include "imageloader.h"

using namespace std;

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: //Escape key
		exit(0);
	}
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image)
{
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,		 //Always GL_TEXTURE_2D
		0,							 //0 for now
		GL_RGB,						 //Format OpenGL uses for image
		image->width, image->height, //Width and height
		0,							 //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
						  //as unsigned numbers
		image->pixels);				 //The actual pixel data
	return textureId;
}

//The id of the texture
GLuint _textureId1;
GLuint _textureId2;

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image* image1 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\crate.bmp"); 
	_textureId1 = loadTexture(image1);
	delete image1;

	Image* image2 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\robot.bmp"); 
	_textureId2 = loadTexture(image2);
	delete image2;
}

void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 1.0f, -6.0f);

	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat directedLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat directedLightPos[] = { -10.0f, 15.0f, 20.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
	glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);

	//Draw a triangle with texture map
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glColor3f(1.0f, 1.0f, 1.0f);
		glScaled(0.6, 0.6, 0.6);
		glTranslated(-3.5, -1, 0);
		glBegin(GL_TRIANGLES);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5f, -2.5f, -2.5f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5f, 2.5f, -2.5f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5f, -2.5f, -2.5f);
		glEnd();
	glPopMatrix();

	//Draw a rectangle with texture map
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId2);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glColor3f(1.0f, 1.0f, 1.0f);
		glScaled(0.6, 0.6, 0.6);
		glTranslated(3.5, -1, 0);
		glBegin(GL_QUADS);
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.5f, -2.5f, -2.5f); //bottom left
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.5f, 2.5f, -2.5f);  //bottom-right
			glTexCoord2f(1.0f, 1.0f); glVertex3f(2.5f, 2.5f, -2.5f);   //top-right
			glTexCoord2f(1.0f, 0.0f); glVertex3f(2.5f, -2.5f, -2.5f);  //top-left
		glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 400);

	glutCreateWindow("Texture Mapping");
	initRendering();
	
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}