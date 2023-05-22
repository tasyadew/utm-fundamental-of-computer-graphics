/*
  * robot.c
  * This program shows how to composite modeling transformations
  * to draw translated and rotated hierarchical models.
  * Interaction:  pressing the s and e keys (shoulder and elbow)
  * alters the rotation of the robot arm.
  */
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, hand = 0, fumb = 0, point = 0, middle = 0, ring = 0, tiny = 0;
static int fumbcap = 0, pointcap = 0, middlecap = 0, ringcap = 0, tinycap = 0;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

//lukis paksi utama
void lukisPaksi()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3i(-100, 0, 0);
    glVertex3i(100, 0, 0);
    glVertex3i(0, -100, 0);
    glVertex3i(0, 100, 0);
    glVertex3i(0, 0, -100);
    glVertex3i(0, 0, 100);
    glEnd();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    lukisPaksi();
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glTranslatef(2.0, 0.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.0, 1.0, 1.0);
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    //Hand
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glScalef(0.5, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();


    //Thumb1
    glPushMatrix();
    glTranslatef(0.0, 0.125, -0.2);
    glRotatef((GLfloat)fumb, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.8);
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glScalef(0.5, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.15, 0.0, -0.8);
    glRotatef((GLfloat)fumb, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.8);
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glScalef(0.5, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //Pointer Finger
    glPushMatrix();
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)point, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.4);
    glPushMatrix();
    glColor3f(0.8, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)point, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.8, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //Middle Finger
    glPushMatrix();
    glTranslatef(0.5, 0.10, 0.0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.65, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    glPushMatrix();
    glColor3f(0.65, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //Ring Finger
    glPushMatrix();
    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -0.4);
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.5, 0.1, 0.0);
    glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //Pinky Finger
    glPushMatrix();
    glTranslatef(0.2, 0.1, 0.0);
    glRotatef((GLfloat)tiny, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, -0.6);
    glPushMatrix();
    glColor3f(0.35, 0.0, 0.0);
    glScalef(0.5, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();

    glTranslatef(0.4, 0.1, 0.0);
    glRotatef((GLfloat)tiny, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.1, 0.0);
    glPushMatrix();
    glColor3f(0.35, 0.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glutSolidCube(0.8);
    glPopMatrix();
    glPopMatrix();


    //End
    glPopMatrix();
    glutSwapBuffers();
    //glDeleteTextures(1,&text1);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 's':
        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
        elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E':
        elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
        //Hand
    case 'h':
        if (hand < 90)
            hand = (hand + 5) % 360;
        glutPostRedisplay();
        break;
    case 'H':
        if (hand > 0)
            hand = (hand - 5) % 360;
        glutPostRedisplay();
        break;

        //Entire Hand!(For Creep-Out Effect)
    case 'c':
        if (fumb < 90)
            fumb = (fumb + 5) % 360;
        if (point < 90)
            point = (point + 5) % 360;
        if (middle < 90)
            middle = (middle + 5) % 360;
        if (ring < 90)
            ring = (ring + 5) % 360;
        if (tiny < 90)
            tiny = (tiny + 5) % 360;
        glutPostRedisplay();
        break;
    case 'C':
        if (fumb > 0)
            fumb = (fumb - 5) % 360;
        if (point > 0)
            point = (point - 5) % 360;
        if (middle > 0)
            middle = (middle - 5) % 360;
        if (ring > 0)
            ring = (ring - 5) % 360;
        if (tiny > 0)
            tiny = (tiny - 5) % 360;
        glutPostRedisplay();
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}