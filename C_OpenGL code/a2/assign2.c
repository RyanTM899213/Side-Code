#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

void init(void) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void displaypoints(int x0, int y0, int x1, int y1) {

    
    //fclose(fileStream);  // close text file
    // loop and code to draw points here!    
}

void display(void) {

    FILE *file;
    file = fopen("input.txt", "r");
    char line[21];
        
    while (!feof(file)) {
        fgets(line,21,file);
        if (strcmp("Z",line) != 0) printf("Token: %s\n", line);
    }
    fclose(file);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        //displaypoints();
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
/*
* Declare initial window size, position, and
* display mode (single buffer and RGBA).
* Open window with "hello" in its title bar.
* Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;  // ANSI C requires main to return int.
}
