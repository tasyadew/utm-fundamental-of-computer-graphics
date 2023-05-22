/*
* Name: Natasya Nadhira Binti Ahmad Nazrain
* Matric No: A20EC0103
* Section: 01
* Lecturer: Dr. Goh Eg Su
* 
* Assignment 1b - Hari Raya Theme
*/

#include <GL/glut.h>
#include <math.h>
#include <string>

#define PI 3.142

//converts GLfloat RGB convention into 255 RGB standard
void setColor(GLfloat r, GLfloat g, GLfloat b) {
	float val = 255.0;
	glColor3f(r / val, g / val, b / val);
}

//initialize function
void init() {
	glClearColor(0.106, 0.145, 0.251, 1); //rgb = (27, 37, 64)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 750, 0, 750);
}

//function to draw circle only
void circle(int x_pos, int y_pos, int radius, GLfloat r, GLfloat g, GLfloat b) {
	setColor(r, g, b);
	float theta;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta = i * PI / 180;
		glVertex2f(x_pos + radius * cos(theta), y_pos + radius * sin(theta));
	}
	glEnd();
}

//function to draw multiple circles in a straight line
void circleLine(int x_pos, int y_pos, int totalLoop) {
	for (int i = 0; i < totalLoop; i++) {
		circle(x_pos, y_pos, 6, 254, 240, 133); //yellow
		y_pos -= 16;
		circle(x_pos, y_pos, 4, 162, 206, 82); //green
		y_pos -= 16;
	}
	circle(x_pos, y_pos, 6, 254, 240, 133); //yellow
}

//function to draw moon
void moon(int x_pos, int y_pos) {
	circle(x_pos, y_pos, 150, 245, 232, 154); //shadow
	circle(x_pos+7, y_pos+12, 145, 255, 250, 188); //base
	circle(x_pos + 40, y_pos + 40, 130, 27, 37, 64); //cut
}

//function to draw star
void star(float x_pos, float y_pos, float radius) {
	const float DegToRad = 3.14159 / 180;
	int numPoints = 7;

	glBegin(GL_TRIANGLE_FAN);
	int count = 1;
	glVertex2f(x_pos, y_pos);
	for (int i = 0; i <= numPoints * 2; i++) {
		float DegInRad = i * 360.0/(numPoints*2) * DegToRad;
		if (count % 2 != 0) {
			setColor(255, 250, 188);
			glVertex2d(x_pos + cos(DegInRad) * radius, y_pos + sin(DegInRad) * radius);
		}
		else {
			//setColor(245, 232, 154);
			setColor(230, 220, 140);
			glVertex2d((x_pos + cos(DegInRad) * radius/2), (y_pos + sin(DegInRad) * radius/2));
		}
		count++;
	}
	glEnd();
}

//function to draw square
void square(float x_pos, float y_pos, float size, GLfloat r, GLfloat g, GLfloat b) {
	glBegin(GL_POLYGON);
	setColor(r, g, b);
	glVertex2f(x_pos, y_pos + size); //top
	glVertex2f(x_pos - size, y_pos); //left
	glVertex2f(x_pos, y_pos - size); //bottom
	glVertex2f(x_pos + size, y_pos); //right
	glEnd();
}

//function to draw ribbon
void ribbon(bool rotation, float x_pos, float y_pos, float size, GLfloat r, GLfloat g, GLfloat b) {
	glBegin(GL_POLYGON);
	setColor(r, g, b);
	
	glVertex2f(x_pos, y_pos + size); //top
	glVertex2f(x_pos - size, y_pos); //left

	//rotation true = left ribbon
	if(rotation) glVertex2f(x_pos, y_pos); //center
	glVertex2f(x_pos, y_pos - size); //bottom

	if (!rotation) glVertex2f(x_pos, y_pos); //center
	glVertex2f(x_pos + size, y_pos); //right

	glEnd();
}

//function to draw ketupat
void ketupat(float flip, float x_pos, float y_pos, float size, GLfloat r1, GLfloat g1, GLfloat b1, GLfloat r2, GLfloat g2, GLfloat b2) {
	//background
	square(x_pos, y_pos, size, r1, g1, b1);

	//mini square
	square(x_pos, y_pos, size/3, r2, g2, b2); //center
	square(x_pos, y_pos + (2.0/3.0 * size), size / 3, r2, g2, b2); //top
	square(x_pos, y_pos - (2.0/3.0 * size), size / 3, r2, g2, b2); //bottom
	square(x_pos - (2.0/3.0 * size), y_pos, size / 3, r2, g2, b2); //left
	square(x_pos + (2.0/3.0 * size), y_pos, size / 3, r2, g2, b2); //right

	//ribbon
	if (flip) {
		ribbon(0, x_pos + (1.0/3.0 * size), y_pos - size, size/3, r1-20, g1-20, b1-20); //bottom right
		ribbon(1, x_pos - (1.0/3.0 * size), y_pos - size, size/3, r2-20, g2-20, b2-20); //bottom left
	}
	else {
		ribbon(0, x_pos + (1.0/3.0 * size), y_pos - size, size/3, r2-20, g2-20, b2-20); //bottom right
		ribbon(1, x_pos - (1.0/3.0 * size), y_pos - size, size/3, r1-20, g1-20, b1-20); //bottom left
	}
}

//function to draw ribbon hanging at the cresent
void longRibbon(int x_pos, int y_pos) {
	//dark green
	glBegin(GL_POLYGON);
	setColor(0, 133-20, 84-20);
	glVertex2f(x_pos, y_pos);
	glVertex2f(x_pos - 25, y_pos + 10);
	glVertex2f(x_pos - 35, y_pos);
	glVertex2f(x_pos - 25, y_pos - 150);
	glVertex2f(x_pos, y_pos - 150);
	glEnd();

	//light green
	glBegin(GL_POLYGON);
	setColor(163, 208, 65);
	glVertex2f(x_pos, y_pos);
	glVertex2f(x_pos + 25, y_pos);
	glVertex2f(x_pos + 35, y_pos - 8);
	glVertex2f(x_pos + 25, y_pos - 150);
	glVertex2f(x_pos, y_pos - 150);
	glEnd();
}

//function to display text
void text(float x, float y, void* font, char* string) {
	char* c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
		glutBitmapCharacter(font, *c); //char datatype can fit into int datatype (implicit conversion)
		x1 = (x1+2) + glutBitmapWidth(font, *c);
	}
}

//function to display Raya text using text function
void rayaText() {
	//text array
	char t1[] = "Selamat";
	char t2[] = "Hari Raya";
	char t3[] = "Sincerely From,";
	char t4[] = "Natasya Nadhira";
	char t5[] = "Binti Ahmad Nazrain";
	char t6[] = "A20EC0103";

	//draw text
	int x_pos = 450;
	int y_pos = 300;
	setColor(87, 185, 64);
	text(x_pos, y_pos, GLUT_BITMAP_TIMES_ROMAN_24, t1);
	setColor(255, 204, 66);
	text(x_pos, y_pos-50, GLUT_BITMAP_TIMES_ROMAN_24, t2);
	setColor(255, 255, 255);
	text(x_pos, y_pos-100, GLUT_BITMAP_HELVETICA_18, t3);
	text(x_pos, y_pos-130, GLUT_BITMAP_9_BY_15, t4);
	text(x_pos, y_pos-150, GLUT_BITMAP_9_BY_15, t5);
	text(x_pos, y_pos-180, GLUT_BITMAP_9_BY_15, t6);
}

//function to display all of the drawn shapes
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	/*
	// For Debugging
	circle(0, 0, 10, 255, 255, 255); // 0,0 white - bottom left
	circle(0, 750, 10, 255, 0, 0);   // 0,750 red - top left
	circle(750, 0, 10, 0, 255, 0);   // 750,0 green - bottom right
	circle(750, 750, 10, 0, 0, 255); // 750,750 blue - top right
	*/

	//raya drawing
	ribbon(0, 275, 320, 80/3.0, 163-20, 208-20, 65-20);
	square(250, 345, 80/3.0, 163-20, 208-20, 65-20);
	moon(220, 500); //crescent
	longRibbon(220, 420); //long ribbon on top of cresent
	circleLine(60, 750, 13);  //left
	circleLine(250, 750, 6);  //mid
	circleLine(340, 750, 14); //right
	star(52, 298, 42);  //left
	star(240, 510, 60); //mid
	star(333, 272, 30); //right
	ketupat(0, 220, 240, 80, 163, 208, 65, 1, 133, 84); //big ketupat
	ketupat(0, 305, 185, 50, 255, 250, 188, 63, 182, 78); //small top ketupat
	ketupat(1, 250, 130, 50, 255, 250, 188, 63, 182, 78); //small bottom ketupat
	rayaText(); //display text

	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("Selamat Hari Raya Aidilfitri! Maaf Zahir dan Batin");

	init();
	glutDisplayFunc(display);
	glutMainLoop();
}