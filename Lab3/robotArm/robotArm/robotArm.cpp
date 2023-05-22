/*
 * robot.c
 * This program shows how to composite modeling transformations
 * to draw translated and rotated hierarchical models.
 * Interaction:  Pressing the s, e and p keys (shoulder, elbow and palm)
 *               alters the rotation of the robot arm.
 *               Hold shift to rotate in the opposite direction.
 *
 * Natasya Nadhira Binti Ahmad Nazrain
 * A20EC0103
 */
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, palm = 0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

//lukis paksi utama
void lukisPaksi()
{
    glColor3f(1, 0, 0);
    int x = 1;
    glBegin(GL_LINES);
    glVertex3i(-x, 0, 0);
    glVertex3i(x, 0, 0);
    glVertex3i(0, -x, 0);
    glVertex3i(0, x, 0);
    glVertex3i(0, 0, -x);
    glVertex3i(0, 0, x);
    glEnd();
}

void finger(float length_prev, float length_finger, bool not_thumb, float z) {
    glTranslatef(length_prev / 2.0 + (length_finger / 2.0) * not_thumb, 0.0, z);
    glPushMatrix();
    glScalef(length_finger, 0.4, 0.5);
    glColor3f(1, 1, 1);
    glutWireCube(1.0);
    glPopMatrix();
    lukisPaksi();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    lukisPaksi();

    float length_shoulder = 3.0;
    float length_elbow = 3.0;
    float length_palm = 1.0;
    float length_finger = 0.7;
    float length_thumb = 0.5;

    //shoulder
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(length_shoulder / 2.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(length_shoulder, 0.4, 1.0);
    glColor3f(1, 1, 1);
    glutWireCube(1.0);
    glPopMatrix();
    lukisPaksi();

    //elbow
    glTranslatef(length_shoulder / 2.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(length_elbow / 2.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(length_elbow, 0.4, 1.0);
    glColor3f(1, 1, 1);
    glutWireCube(1.0);
    glPopMatrix();
    lukisPaksi();

    //palm
    glTranslatef(length_elbow / 2.0, 0.0, 0.0);
    glRotatef((GLfloat)palm, 1.0, 0.0, 0.0);
    glTranslatef(length_palm / 2.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(length_palm, 0.4, 1.5);
    glColor3f(1, 1, 1);
    glutWireCube(1.0);
    glPopMatrix();
    lukisPaksi();

    //fingers
    finger(length_palm, length_finger, true, -0.5);
    finger(-length_finger, length_finger, true, 0.5);
    finger(-length_finger, length_finger, true, 0.5);
    finger(-length_finger, length_thumb, false, 0.5);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
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
    case 'p':
        palm = (palm + 5) % 360;
        glutPostRedisplay();
        break;
    case 'P':
        palm = (palm - 5) % 360;
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
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutSetWindowTitle("Robot Arm by Natasya Nadhira A20EC0103");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}