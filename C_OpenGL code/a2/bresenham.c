/** bresenham.c
    CS4751 - Graphics
    Assignment 2
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

// we have separate methods to call from display which draws each shape,
// depending on the shape indicated in the text file.
void displayLine(int x0, int y0, int x1, int y1) {  // draws lines using bresenham's algorithm

    int dY = y1 - y0;  // constants
    int dX = x1 - x0;
    int tDY = 2 * dY;
    int dYX = tDY - (2 * dX);
    int dk = tDY - dX; 
    int k = 0;
    int xk = x0;
    int yk = y0;
    
    glBegin(GL_POINTS);
         glColor3f(0.0,0.0,0.0);  // set the color
         glVertex2f(x0 / 500.0, y0 / 500.0); // divide by 500 to be in frame
         while (k != dX) {
         
            if (dk < 0) {
            
                glVertex2f((xk + 1.0) / 500.0, yk / 500.0);
                dk = dk + tDY;  // update dk
            }
            else {
            
                glVertex2f((xk + 1.0) / 500.0, (yk + 1.0) / 500.0);
                dk = dk + dYX;  // update dk
            }
            k++;  // increment counters
            xk++;
            yk++;        
         }
    glEnd();
}

// this method takes x, y and r values to produce a circle in a window
// with the given algorithm below
void displayCircle(int x, int y, int r) {

    int dE = 3;
    int sE = 5 - (2 * r);
    int dK = 1 - r;
    int xn = r;
    int yn = 0;

    glBegin(GL_POINTS);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(x / 500.0, y / 500.0);
        while (xn >= yn) {
        
            if (dK < 0) {
            
                dK = dK + dE;
                dE = dE + 2;
                sE = sE + 2; 
            }
            else {
            
                dK = dK + sE;
                dE = dE + 2;
                sE = sE + 4;
                xn--;
            }  // draw points
             glVertex2f((xn + x) / 500.0, (yn + y) / 500.0);
             glVertex2f((yn + x) / 500.0, (xn + y) / 500.0);
             glVertex2f((-xn + x) / 500.0, (yn + y) / 500.0);
             glVertex2f((-yn + x) / 500.0, (xn + y) / 500.0);
             glVertex2f((-xn + x) / 500.0, (-yn + y) / 500.0);
             glVertex2f((-yn + x) / 500.0, (-xn + y) / 500.0);
             glVertex2f((xn + x) / 500.0, (-yn + y) / 500.0);
             glVertex2f((yn + x) / 500.0, (-xn + y) / 500.0);
             yn++;
        }
    glEnd();
}

// displays polygons read from the text file. takes three vertices and draws
// the shape depending on the values
void displayPoly(int x0, int y0, int x1, int y1, int x2, int y2) {

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(x0 / 500.0, y0 / 500.0);
        glVertex2f(x1 / 500.0, y1 / 500.0);
        glVertex2f(x2 / 500.0, y2 / 500.0);
    glEnd();
}

// reads the text file, and depending on what letter each line contains, it 
// draws the corresponding shape by calling the appropriate method above.
void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
    FILE *file;
    file = fopen("lines", "rt");  // opens lines.txt. *change to file input name*
    char line[81];  // array of size 80 to store lines of file
    
    while (!feof(file)) {  // while !end of file

       char type;
       fscanf(file, "%c", &type);
       if (type == 'L') {  // line
       
           int x0, y0, x1, y1;
           fscanf(file, "%i, %i, %i, %i\n", &x0, &y0, &x1, &y1);
           displayLine(x0,y0,x1,y1);
       }
       else if (type == 'C') {  // circle
       
           int x, y, r;
           fscanf(file,"%i, %i, %i\n", &x, &y, &r);
           displayCircle(x,y,r);  
       }
       else if (type == 'P') {  // polygon
       
           int x0,y0,x1,y1,x2,y2;
           fscanf(F, "%i, %i, %i, %i, %i, %i\n", &x0, &y0, &x1, &y1, &x2, &y2);
           displayPoly(x0,y0,x1,y1,x2,y2);
       } 
    }
    fclose(file);  // close file
    glFlush();
}

void resize(int w, int h) {  // resize function

	glViewport(0, h - 500, w, 500);
}
		
int main(int argc, char** argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("assignment 2");

	init();	
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMainLoop();
	return 0; // required
}
