#include <Windows.h>
#include <iostream>
#include <GL/glut.h>
#include "imageloader.h"

using namespace std;

//for angle of rotation
static int x_rotate = 180;
static int y_rotate = 180;

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
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;
GLuint _textureId6;

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image* image1 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\1.bmp");
	_textureId1 = loadTexture(image1);
	delete image1;
	
	Image* image2 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\2.bmp");
	_textureId2 = loadTexture(image2);
	delete image2;

	Image* image3 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\3.bmp");
	_textureId3 = loadTexture(image3);
	delete image3;

	Image* image4 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\4.bmp");
	_textureId4 = loadTexture(image4);
	delete image4;

	Image* image5 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\5.bmp");
	_textureId5 = loadTexture(image5);
	delete image5;

	Image* image6 = loadBMP("C:\\Users\\Natasya\\Documents\\CODE\\UTM\\SEM4\\CG\\bmp\\6.bmp");
	_textureId6 = loadTexture(image6);
	delete image6;
	
}

void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

//Draw a rectangle with texture map
void drawSquare(GLuint texture, float arr[]) {
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslated(3.5, -1, 0);
	glRotatef((GLfloat)x_rotate, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)y_rotate, 0.0, 1.0, 0.0);
	glScaled(0.6, 0.6, 0.6);
	
	glBegin(GL_QUADS);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(arr[0], arr[1], arr[2]); //bottom left
		glTexCoord2f(0.0f, 1.0f); glVertex3f(arr[3], arr[4], arr[5]);  //bottom-right
		glTexCoord2f(1.0f, 1.0f); glVertex3f(arr[6], arr[7], arr[8]);   //top-right
		glTexCoord2f(1.0f, 0.0f); glVertex3f(arr[9], arr[10], arr[11]);  //top-left
		glEnd();
	glPopMatrix();
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-2.0f, 1.0f, -10.0f);

	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat directedLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat directedLightPos[] = { -10.0f, 15.0f, 20.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
	glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);



	//Define array of vertices for each face
	float arr_front[] = { -2.5f,-2.5f, 2.5f,
						  -2.5f, 2.5f, 2.5f,
						  2.5f,  2.5f, 2.5f,
						  2.5f, -2.5f, 2.5f };

	float arr_right[] = { 2.5f, -2.5f, 2.5f,
						  2.5f,  2.5f, 2.5f,
						  2.5f,  2.5f, -2.5f,
						  2.5f, -2.5f, -2.5f };

	float arr_back[] = { -2.5f, -2.5f, -2.5f,
						 -2.5f,  2.5f, -2.5f,
						  2.5f,  2.5f, -2.5f,
						  2.5f, -2.5f, -2.5f };

	float arr_left[] = {  -2.5f, -2.5f, -2.5f,
						  -2.5f,  2.5f, -2.5f,
						  -2.5f,  2.5f,  2.5f,
						  -2.5f, -2.5f,  2.5f };

	float arr_top[] = {   -2.5f, 2.5f, 2.5f,
						   2.5f, 2.5f, 2.5f,
						   2.5f, 2.5f, -2.5f,
						  -2.5f, 2.5f, -2.5f };

	float arr_bottom[] = { -2.5f, -2.5f, 2.5f,
						    2.5f, -2.5f, 2.5f,
						    2.5f, -2.5f, -2.5f,
						   -2.5f, -2.5f, -2.5f };

	//Draw a box with texture map
	drawSquare(_textureId3, arr_front);  //3
	drawSquare(_textureId2, arr_right);  //2
	drawSquare(_textureId4, arr_back);   //4
	drawSquare(_textureId5, arr_left);	 //5
	drawSquare(_textureId6, arr_top);    //6
	drawSquare(_textureId1, arr_bottom); //1


	glutSwapBuffers();
	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':
		x_rotate = (x_rotate + 5) % 360;
		break;
	case 'X':
		x_rotate = (x_rotate - 5) % 360;
		break;
	case 'y':
		y_rotate = (y_rotate + 5) % 360;
		break;
	case 'Y':
		y_rotate = (y_rotate - 5) % 360;
		break;
	case 27: //Escape key
		exit(0);
		break;
	}
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(600, 400);

	glutCreateWindow("Multiple Texture Mapping - Dice");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}