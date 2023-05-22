/*
  * MikeWazoski.cpp
  * This program renders a 3D model of Mike Wazowski that repeats a walk cycle.
  * The arms and legs rotates using product with sinf() and cosf() values so that
  * it swings back and forth. The body also bobs up and down using the same
  * sinf() cosf() technique. Mike Wazowski also blinks every 8th walk cycle loops
  * by drawing a seperate sphere on top of the eyes.
  * 
  * Interaction:
  * - Press [W] to manually play the walking animation
  * - Press [Shift+W] to switch to automatic walking mode
  * - Press [R] or [Shift+R] to rotate Mike Wazowski along the Y axis
  * - Press [D] to toggle Debug mode and change the color of his arms and legs
  * - Press [Arrow Keys] to view Mike Wazoski from a specific side
  * - Press [J] or [L] to move the camera along the X-axis
  * - Press [K] or [I] to move the camera along the Y-axis
  * - Press [H] or [Y] to move the camera along the Z-axis
  */
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

static int bodyRotation = 180, walkFrame = 0, walkLoop = 0, sideX = 0, sideY = 0;
static float PI = 3.1415926f, camX = 0.0f, camY = 0.0f, camZ = 5.0f, upX = 0.0f, upY = 1.0f, upZ = 0.0f;
static bool debug = false, loopEnd = false, camSwitchedSides = false, autoWalk = true;

void init(void) {
	glClearColor(45.0 / 255.0, 45.0 / 255.0, 48.0 / 255.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, 0.0f, 0.0f, 0.0f, upX, upY, upZ);
}

void DrawCircle(float radius, float scaleX, float scaleY) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 20.0; i++) {
        float theta = 2.0f * PI * float(i) / 20.0;

        float x = radius * cosf(theta);
        float y = radius * sinf(theta);

        glVertex2f(x * scaleX, y * scaleY);
    }
    glEnd();
}

void DrawAxes(){
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0); //Red
    glVertex3i(-3.0, 0.0, 0.0);
    glVertex3i(3.0, 0.0, 0.0);
    glEnd();
    
    glPushMatrix();
        glTranslatef(3.0, 0.0, 0.0);
        glRotatef(90, 0.0, 1.0, 0.0);
        glutSolidCone(0.1, 0.25, 20.0, 16.0);
    glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0); //Green
    glVertex3i(0.0, -3.0, 0.0);
    glVertex3i(0.0, 3.0, 0.0);
    glEnd();

    glPushMatrix();
        glTranslatef(0.0, 3.0, 0.0);
        glRotatef(90, -1.0, 0.0, 0.0);
        glutSolidCone(0.1, 0.25, 20.0, 16.0);
    glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0); //Blue
    glVertex3i(0.0, 0.0, -3.0);
    glVertex3i(0.0, 0.0, 3.0);
    glEnd();

    glPushMatrix();
        glTranslatef(0.0, 0.0, 3.0);
        glutSolidCone(0.1, 0.25, 20.0, 16.0);
    glPopMatrix();
}

//MODEL
void body() {
    if (debug) DrawAxes();

    glPushMatrix();
        //Body
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glColor3f(167.0 / 255.0, 203.0 / 255.0, 77.0 / 255.0); //Lime
        glutSolidSphere(1.0, 20.0, 16.0); 
    glPopMatrix();
    
    glPushMatrix();
        //Right Horn
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(0.5, 0.8, 0.0);
        glRotatef(-90.0, 1.0, -0.5, 0.0);
        glColor3f(250.0 / 255.0, 245.0 / 255.0, 220.0 / 255.0); //Bone White
        glutSolidCone(0.125, 0.25, 20.0, 16.0); 
    glPopMatrix();

    glPushMatrix();
        //Left Horn
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(-0.5, 0.8, 0.0);
        glRotatef(-90.0, 1.0, 0.5, 0.0);
        glColor3f(250.0 / 255.0, 245.0 / 255.0, 220.0 / 255.0); //Bone White
        glutSolidCone(0.125, 0.25, 20.0, 16.0); 
    glPopMatrix();

    glPushMatrix();
        //Mouth
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(0.0, -0.5, -0.8);
        glColor3f(0.1, 0.1, 0.1); //Dark Grey
        DrawCircle(0.2, 2.0, 1.0);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        //Left Teeth
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(0.15, -0.45, -0.81);
        glColor3f(250.0 / 255.0, 245.0 / 255.0, 220.0 / 255.0); //Bone White
        DrawCircle(0.1, 1.0, 2.0);
    glPopMatrix();

    glPushMatrix();
        //Right Teeth
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(-0.15, -0.45, -0.81);
        glColor3f(250.0 / 255.0, 245.0 / 255.0, 220.0 / 255.0); //Bone White
        DrawCircle(0.1, 1.0, 2.0);
    glPopMatrix();

    glPushMatrix();
        //Eye
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(0.0, 0.1, -0.55);
        glColor3f(1.0, 1.0, 1.0); //White
        glutSolidSphere(0.6, 20.0, 16.0); 

        //Iris
        glTranslatef(0.0, 0.0, -0.3);
        glColor3f(100.0/255.0, 120.0/255.0, 14.0/255.0); //Dark Emerald
        glutSolidSphere(0.35, 20.0, 16.0);

        //Pupil
        glTranslatef(0.0, 0.0, -0.2);
        glColor3f(0.0, 0.0, 0.0); //Black
        glutSolidSphere(0.175, 20.0, 16.0);

        //Highlight
        glTranslatef(-0.075, 0.075, -0.05);
        glColor3f(1.0, 1.0, 1.0); //White
        glutSolidSphere(0.1, 20.0, 16.0);
    glPopMatrix();
}

void left_arm() {
    glPushMatrix();
        glColor3f(167.0 / 255.0, 203.0 / 255.0, 77.0 / 255.0); //Lime

        //Shoulder
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(-1.0, -0.3, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Arm
        glRotatef(22.5 * sinf((GLfloat)walkFrame * -PI / 180) - 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.2, 0.0);
        glScalef(0.2, 0.4, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

void left_forearm() {
    glPushMatrix();
        glColor3f(167.0 / 255.0, 203.0 / 255.0, 77.0 / 255.0); //Lime

        //Elbow
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(-1.0, -0.3, 0.0);
        glRotatef(22.5 * sinf((GLfloat)walkFrame * -PI / 180) - 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.4, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Forearm
        glRotatef(45 * cosf((GLfloat)walkFrame * PI / 180) + 45.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.2, 0.0);
        glScalef(0.2, 0.4, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
        glScalef(1.0 / 0.2, 1.0 / 0.4, 1.0 / 0.2); //Revert scale back to (1.0, 1.0, 1.0)

        //Hand
        glTranslatef(0.0, -0.4, 0.0);
        glScalef(0.175, 0.4, 0.3);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
        glScalef(1.0 / 0.175, 1.0 / 0.4, 1.0 / 0.3); //Revert scale back to (1.0, 1.0, 1.0)

        //Thumb
        glTranslatef(0.0, 0.1125, -0.15);
        glRotatef(-90, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0875, 0.0);
        glScalef(0.175, 0.175, 0.175);
        if (debug) glColor3f(0.25, 0.25, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

void right_arm() {
    glPushMatrix();
        //Shoulder
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(1.0, -0.3, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Arm
        glRotatef(22.5 * sinf((GLfloat)walkFrame * PI / 180) - 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.2, 0.0);
        glScalef(0.2, 0.4, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

void right_forearm() {
    glPushMatrix();
        //Elbow
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(1.0, -0.3, 0.0);
        glRotatef(22.5 * sinf((GLfloat)walkFrame * PI / 180) - 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.4, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Forearm
        glRotatef(45 * cosf((GLfloat)walkFrame * -PI / 180) - 45.0, -1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.2, 0.0);
        glScalef(0.2, 0.4, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
        glScalef(1.0 / 0.2, 1.0 / 0.4, 1.0 / 0.2); //Revert scale back to (1.0, 1.0, 1.0)

        //Hand
        glTranslatef(0.0, -0.4, 0.0);
        glScalef(0.175, 0.4, 0.3);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
        glScalef(1.0 / 0.175, 1.0 / 0.4, 1.0 / 0.3); //Revert scale back to (1.0, 1.0, 1.0)

        //Thumb
        glTranslatef(0.0, 0.1125, -0.15);
        glRotatef(-90, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0875, 0.0);
        glScalef(0.175, 0.175, 0.175);
        if (debug) glColor3f(0.25, 0.25, 1.0);
        else glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

void left_upper_leg() {
    glPushMatrix();
        //Hip Joint
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(-0.4, -0.9, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Upper Leg
        glRotatef(22.5 * sinf((GLfloat)walkFrame * PI / 180) + 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.25, 0.0);
        glScalef(0.2, 0.5, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

void left_lower_leg() {
    glPushMatrix();
        //Knee
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(-0.4, -0.9, 0.0);
        glRotatef(22.5 * sinf((GLfloat)walkFrame * PI / 180) + 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.5, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Lower Leg
        glRotatef(45 * cosf((GLfloat)walkFrame * -PI / 180) + 45.0, -1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.25, 0.0);
        glScalef(0.2, 0.5, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidCube(1.0);
        glScalef(1.0 / 0.2, 1.0 / 0.6, 1.0 / 0.2); //Revert scale back to (1.0, 1.0, 1.0)

        //Feet
        glTranslatef(0.0, -0.3375, -0.1);
        glScalef(0.3, 0.175, 0.5);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

void right_upper_leg() {
    glPushMatrix();
        //Hip Joint
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(0.4, -0.9, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Upper Leg
        glRotatef(22.5 * sinf((GLfloat)walkFrame * -PI / 180) + 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.25, 0.0);
        glScalef(0.2, 0.5, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

void right_lower_leg() {
    glPushMatrix();
        //Knee
        glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
        glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
        glTranslatef(0.4, -0.9, 0.0);
        glRotatef(22.5 * sinf((GLfloat)walkFrame * -PI / 180) + 22.5, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.5, 0.0);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidSphere(0.125, 20.0, 16.0);

        //Lower Leg
        glRotatef(45 * cosf((GLfloat)walkFrame * PI / 180) - 45.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, -0.25, 0.0);
        glScalef(0.2, 0.5, 0.2);
        if (debug) glColor3f(1.0, 0.0, 0.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidCube(1.0);
        glScalef(1.0 / 0.2, 1.0 / 0.6, 1.0 / 0.2); //Revert scale back to (1.0, 1.0, 1.0)

        //Feet
        glTranslatef(0.0, -0.3375, -0.1);
        glScalef(0.3, 0.175, 0.5);
        if (debug) glColor3f(0.0, 0.0, 1.0);
        else glColor3f(142.0 / 255.0, 178.0 / 255.0, 52.0 / 255.0); //Slightly More Darker Lime
        glutSolidCube(1.0);
    glPopMatrix();
}

//KEYBOARD
void specialInput(int key, int x, int y) {
    switch (key) {    
    case GLUT_KEY_UP:
        if (sideY < 1) sideY++;
        camSwitchedSides = true;
        break;
    case GLUT_KEY_DOWN:
        if (sideY > -1) sideY--;
        camSwitchedSides = true;
        break;
    case GLUT_KEY_RIGHT:
        sideX--;
        camSwitchedSides = true;
        break;
    case GLUT_KEY_LEFT:
        sideX++;
        camSwitchedSides = true;
        break;
    default:
        break;
    }

    if (camSwitchedSides) {
        if (sideX > 3) sideX = 0;
        else if (sideX < 0) sideX = 3;

        if (sideX == 0) {
            camX = 0.0f;
            camZ = 5.0f;
        } else if (sideX == 1) {
            camX = 5.0f;
            camZ = 0.0f;
        } else if (sideX == 2) {
            camX = 0.0f;
            camZ = -5.0f;
        } else if (sideX == 3) {
            camX = -5.0f;
            camZ = 0.0f;
        }

        if (sideY == 1) {
            camX = 0.0f;
            camY = 5.0f;
            camZ = 0.0f;
            upY = 0.0f;
            upZ = -1.0f;
        } else if (sideY == 0) {
            camY = 0.0f;
            upY = 1.0f;
            upZ = 0.0f;
        } else if (sideY == -1) {
            camX = 0.0f;
            camY = -5.0f;
            camZ = 0.0f;
            upY = 0.0f;
            upZ = 1.0f;
        }

        camSwitchedSides = false;
    }

    glLoadIdentity();
    gluLookAt(camX, camY, camZ, 0.0f, 0.0f, 0.0f, upX, upY, upZ);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r':
        bodyRotation = (bodyRotation + 5) % 360;
        break;
    case 'R':
        bodyRotation = (bodyRotation - 5) % 360;
        break;
    case 'w':
        autoWalk = false;
        walkFrame = (walkFrame + 2) % 360;
        break;
    case 'W':
        autoWalk = true;
        break;
    case 'd':
        debug = !debug;
        break;
    case 'D':
        debug = !debug;
        break;
    case 'j': case 'J':
        camX--;
        break;
    case 'l': case 'L':
        camX++;
        break;
    case 'k': case 'K':
        camY--;
        break;
    case 'i': case 'I':
        camY++;
        break;
    case 'y' : case 'Y':
        camZ++;
        break;
    case 'h': case 'H':
        camZ--;
        break;
    case 27: //Esc key
        exit(0);
        break;
    default:
        break;
    }

    glLoadIdentity();
    gluLookAt(camX, camY, camZ, 0.0f, 0.0f, 0.0f, upX, upY, upZ);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    //Render all body parts
    body();
    left_arm();
    left_forearm();
    right_arm();
    right_forearm();
    left_upper_leg();
    left_lower_leg();
    right_upper_leg();
    right_lower_leg();

    //Plays walk cycle animation faster depending on Walking or Running mode
    if (autoWalk) {
        walkFrame = (walkFrame + 1) % 360;
    }

    
    //Counts how many walk cycle loops has been completed. Clears terminal after final loop
    if (walkFrame >= 355 && !loopEnd) {
        walkLoop = (walkLoop + 1) % 8;
        loopEnd = true;
    } else if (walkFrame <= 4 && loopEnd) {
        if (walkLoop == 0) system("CLS");
        loopEnd = false;
    }
    
    //Blinks when at the last walk cycle loop (walkLoop #8)
    if (walkFrame >= 270 && walkLoop == 7 && !loopEnd) {
        glPushMatrix();
            //Eyelid
            glTranslatef(0.0, 0.025 * sinf((GLfloat)walkFrame * PI / 90), 0.0);
            glRotatef((GLfloat)bodyRotation, 0.0, 1.0, 0.0);
            glTranslatef(0.0, 0.1, -0.65);
            glColor3f(157.0 / 255.0, 193.0 / 255.0, 67.0 / 255.0); //Slightly Darker Lime
            glutSolidSphere(0.6, 20.0, 16.0);
        glPopMatrix();
    }

    std::cout << "walkFrame: " << walkFrame << " | walkLoop: " << walkLoop << std::endl;

    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mike Wazowski");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialInput);
    glutMainLoop();
    return 0;
}