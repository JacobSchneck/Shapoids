#include "graphics.h"
#include "cube.h"
#include "tetrahedron.h"
#include "sphere.h"

#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;
Cube c;
Tetrahedron t;
Sphere s;


void init() {
    width = 500;
    height = 500;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat lineWidthRange[2] = {0.0f, 0.0f};
    glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);
    gluLookAt(2.0, 3.0, 6.0,  // eye position
              0.0, 0.0, 0.0,  // center position (not gaze direction)
              0.0, 1.0, 0.0); // up vector
}

void draw_axes() {
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-width/2.0, 0.0, 0.0);
    glVertex3f(width/2.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, height/2.0, 0.0);
    glVertex3f(0.0, -height/2.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, width);
    glVertex3f(0.0, 0.0, -width);
    glEnd();
}

void draw_sphere() {
    int radius = 50;
	int total = 100;
	vector<double> lon;
	vector<double> lat;
	lon.resize(total);
	lat.resize(total);

	// initalizing some things;
    // cout << M_PI << endl;
	lon[0] = -M_PI;
	double lon_step = 2*M_PI / total;
	lat[0] = -M_PI;
	double lat_step = 2*M_PI / total;

	for (int i = 1; i < total; i++) {
		lon[i] = lon[i - 1] + lon_step;
		lat[i] = lat[i - 1] + lat_step;
        // cout << "(" << lon[i - 1] << ", " << lat[i - 1] << ") | ";
	}
        // cout << "(" << lon[total - 1] << ", " << lat[total - 1] << ")" << endl;
	
	// other thing	
    glBegin(GL_POINTS);
	for (int i = 0; i < total; i++ ) {
		for( int j = 0; j < total; j++) {		
			double x = radius * cos(lon[i]) * sin(lat[j]);
			double y = radius * sin(lon[i]) * sin(lat[j]);
			double z = radius * cos(lat[j]);
            glColor3f(1, 0, 0);
			glVertex3f(x, y, z);
		}
	}
    glEnd();
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {

    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width/2, width/2, -height/2, height/2, -width, width);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glEnable(GL_DEPTH);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT, GL_FILL);
    
    /*
     * Draw here
     */
    draw_axes();
    // c.draw();
    // t.draw();
    // glBegin(GL_TRIANGLE_FAN);
    //     glColor3f(1, 0, 0);
    //     glVertex3f(40, 50, 60);
    //     glVertex3f(60, 40, 50);
    //     glVertex3f(50, 60, 40);
    // glEnd();
    // draw_sphere();
    s.draw();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(0.5f);
    glColor3f(1, 1, 1);
    s.draw();
    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    switch(key) {
        case 'x': s.rotate(PI / 100.0, 0, 0);
            break;
        case 'z': s.rotate(0, PI / 100.0, 0);
            break;
        case 'c': s.rotate(0, 0, PI / 100.0);
            break;
        case 'g': c.grow(10);
            break;
        case 's': c.shrink(10);
            break;
        case ',': c.move(0, -5, 0);
            break;
        case '.': c.move(0, 5, 0);
            break;
    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            c.move(0, 0 , 5);
            break;
        case GLUT_KEY_LEFT:
            c.move(-5, 0, 0);
            break;
        case GLUT_KEY_RIGHT:
            c.move(5, 0, 0);
            break;
        case GLUT_KEY_UP:
            c.move(0, 0 , -5);
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("3D Graphics!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
