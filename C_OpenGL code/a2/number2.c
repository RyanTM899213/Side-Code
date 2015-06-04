/** bresenham.c
    CS4751 - Graphics
    Assignment 2, Question 1
	Ryan Martin 
	201039054 */

#include <GL/glut.h>
#include <stdio.h> 

void init(void) {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display(void) {


}

void resize(int w, int h) {

	glViewport(0, h-500, w, 500);
}
		
int main(int argc, char** argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("assignment 2 - question 2");

	init();	
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0; // required
}
