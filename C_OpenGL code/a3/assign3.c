/** CS 4751 - Graphics
  * Assignment 3
  * Ryan Martin
  * 201039054
  * rtm773
  * Nov. 7/14
  */

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

/* Define the constants (easier to change them) */
#define BASE_HEIGHT 2.0
#define BASE_RADIUS 1.0
#define LOWER_ARM_HEIGHT 5.0
#define LOWER_ARM_WIDTH 0.5
#define UPPER_ARM_HEIGHT 5.0
#define UPPER_ARM_WIDTH 0.5

typedef float point[3];
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 0;
GLUquadricObj *p; /* pointer to quadric object */

/* Define the three parts */
/* Note use of push/pop to return modelview matrix
to its state before functions were entered and use
rotation, translation, and scaling to create instances
of symbols (cube and cylinder) */
void base() {
    glPushMatrix();
    /* rotate cylinder to align with y axis */
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    /* cylinder aligned with z axis, render with
    5 slices for base and 5 along length */
    gluCylinder(p, BASE_RADIUS, BASE_RADIUS,BASE_HEIGHT, 5, 5);
    glPopMatrix();
}

void left_upper_arm() {
    glPushMatrix();
    glTranslatef(0.5, 0.5*UPPER_ARM_HEIGHT, 0.0);
    glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT,UPPER_ARM_WIDTH);
    glutWireCube(1.0);
    glPopMatrix();
}

void right_upper_arm() {
    glPushMatrix();
    glTranslatef(0.5, 0.5*UPPER_ARM_HEIGHT, 0.0);
    glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT,UPPER_ARM_WIDTH);
    glutWireCube(1.0);
    glPopMatrix();
}

void lower_arm() {
    glPushMatrix();
    glTranslatef(0.0, 0.5*LOWER_ARM_HEIGHT, 0.0);
    glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
    glutWireCube(1.0);
    glPopMatrix();
}

void display(void) {
    /* Develop ModelView Matrix as we traverse structure */
    
    glRotatef(theta[0], 0.0, 1.0, 0.0);
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);
    base();
    glLoadIdentity();
    glTranslatef(0.0, BASE_HEIGHT, 0.0);
    glRotatef(theta[1], 0.0, 0.0, 1.0);
    lower_arm();
    glLoadIdentity();
    glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
    glRotatef(90.0/*theta[2]*/, -1.0, 0.0, 0.0);  // here
    right_upper_arm();
    glLoadIdentity();
    glRotatef(90.0/*theta[2]*/, 0.0, 1.0, 0.0);  // & here
    left_upper_arm();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}



void menu(int id) {  // menu callback function

   // if(id == 1) // body rotation 
   // if(id == 2) // head rotation
   // if(id == 3) // arm rotation
   // if(id == 4) // thumb rotation
}

void myReshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) glOrtho(-10.0,10.0, -5.0 * (GLfloat)h / (GLfloat)w,15.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else glOrtho(-10.0 * (GLfloat)w / (GLfloat)h,10.0 * (GLfloat)w / (GLfloat)h, -5.0,15.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    p = gluNewQuadric(); /* allocate quadric object */
    gluQuadricDrawStyle(p, GLU_LINE); /* draw as wireframe*/
}

void mouse(int btn, int state, int x, int y) {
    /* left button increase joint angle, right decreases */
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        theta[axis] += 5.0;
        if(theta[axis] > 360.0) theta[axis] -= 360.0;
    }
    
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        theta[axis] -= 5.0;
        if(theta[axis] < 360.0) theta[axis] += 360.0;
    }
    display();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    
        case 27:
            exit(0);
            break;
    }
}

void main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("robot");
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);  // exit the program when esc is pressed
    glutCreateMenu(menu);
    glutAddMenuEntry("body rotation", 1);
    glutAddMenuEntry("head rotation", 2);
    glutAddMenuEntry("arm rotation", 3);
    glutAddMenuEntry("thumb rotation", 4);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
}
