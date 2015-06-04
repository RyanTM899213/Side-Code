/** CS 4751 - Graphics
  * Assignment 4
  * Ryan Martin
  * 201039054
  * Nov. 28/14
  */

#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float angle = 0.0, lx = 0.0f, lz = -1.0f, x = 0.0f, z = 5.0f;  // all floats
GLfloat ctrlpts[4][4][3]={ {{-0.45,0.0,-0.45}, {-0.15,0.0,-0.45}, {0.15,0.0,-0.45}, {0.45,0.0,-0.45}},
	{{-0.45,0.0,-0.15}, {-0.15,0.2,-0.15}, {0.15,0.2,-0.15}, {0.45,0.0,-0.15}},
	{{-0.45,0.0, 0.15}, {-0.15,0.2, 0.15}, {0.15,0.2, 0.15}, {0.45,0.0, 0.15}},
	{{-0.45,0.0, 0.45}, {-0.15,0.0, 0.45}, {0.15,0.0, 0.45}, {0.45,0.0, 0.45}} };
	
void bezier() {  // draws the bezier cube

	glPushMatrix();
	glTranslatef(0.0f, 0.45f, 0.0f);
    glRotatef(0.0, 0.0, 0.0, 1.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, -0.45f, 0.0f);
    glRotatef(180.0, 1.0, 0.0, 0.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.45f);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.45f);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
	glPushMatrix();
	glTranslatef(0.45f, 0.0f, 0.0f);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.45f, 0.0f, 0.0f);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glEvalMesh2(GL_FILL, 0, 20, 0, 20);
    glPopMatrix();
}

void draw() {

	glPushMatrix();  // sphere	
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);
	glPopMatrix();
	glPushMatrix();  // cone
	glTranslatef(3.0f, 0.0f, 0.0f);
	glRotatef(-90, 1, 0, 0);
	glColor3f(0.0f, 0.0f, 1.0f);	
	glutSolidCone(0.5f, 1.0f, 10, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.0f, 0.65f, 0.0f);
	glColor3f(1.0, 0.0, 0.0);
	bezier();
	glPopMatrix();
}

void changeSize(int w, int h) {

	if (h == 0) h = 1;
	float ratio = w * 1.0 / h;
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	// Reset Matrix
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
void renderScene(void) {	
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
	// Draw ground and walls
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glEnd();
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glVertex3f(-20.0f, 20.0f, 20.0f);
	glVertex3f(-20.0f, 20.0f, -20.0f);
	glEnd();
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 20.0f, 20.0f);
	glVertex3f(20.0f, 20.0f, -20.0f);
	glEnd();
	glColor3f(0.2f, 0.2f, 0.2f);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 20.0f, -20.0f);
	glVertex3f(20.0f, 20.0f, -20.0f);
	glEnd();
	// Draw Shapes
	glPushMatrix();
	glTranslatef(0.0, 0, -5.0);
	draw();
	glPopMatrix();
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27) exit(0);
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;
	switch(key) {
		case GLUT_KEY_LEFT:
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT:
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP:
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN:
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

void myinit(void) { 
   
	// Enable lighting and the light we have set up
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
    //Set lighting parameters
	GLfloat lightColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light[] = {0.0f, 0.0f, 0.0f, 1.0f};    
	glLightfv(GL_LIGHT0,GL_POSITION,light);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightColor);
	// Enable shading
    glShadeModel(GL_SMOOTH);	
	glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpts[0][0][0]);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("-Assign 4-");
	myinit();
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	// OpenGL init
	glEnable(GL_DEPTH_TEST);
	// enter GLUT event processing cycle
	glutMainLoop();
	return 1;
}
