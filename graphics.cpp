#include "graphics.h"
#include "3D_Shapes/cube.h"
#include "3D_Shapes/tetrahedron.h"
#include "3D_Shapes/sphere.h"
#include "button.h"

#include <math.h>
#include <iostream>
#include <vector>
using namespace std;


Shape shape = CUBE;

GLdouble width, height;
int wd;
Cube c;
Tetrahedron t;
Sphere s;
// Button b = Button("Button", {-200, 200, 0});
Button cube_button = Button("Cube", {-210, 230, 0});
Button tetrahedron_button = Button("Tetrahedron", {-140, 230, 0});
Button sphere_button = Button("Sphere", {-70, 230, 0});

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
    // gluLookAt(2.0, 3.0, 6.0,  // eye position
            //   0.0, 0.0, 0.0,  // center position (not gaze direction)
            //   0.0, 1.0, 0.0); // up vector
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
    cube_button.draw(CUBE);
    tetrahedron_button.draw(TETRAHEDRON);
    sphere_button.draw(SPHERE);

    draw_axes();
    switch(shape) {
        case CUBE: c.draw();
            break;
        case TETRAHEDRON: t.draw();
            break;
        case SPHERE: 
            s.draw();
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glLineWidth(0.5f);
            glColor3f(1, 1, 1);
            s.draw();
            break;
    }
    // c.draw();
    // // t.draw();

    // // s.draw();
    // // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // // glLineWidth(0.5f);
    // // glColor3f(1, 1, 1);
    // // s.draw();
    
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
        case 'x': 
            switch(shape) {
                case CUBE: c.rotate(PI / 100.0, 0, 0);
                    break;
                case TETRAHEDRON: t.rotate(PI / 100.0, 0, 0);
                    break;
                case SPHERE: s.rotate(PI / 100.0, 0, 0);
                    break;
            }
            break;
        case 'z': 
            switch(shape) {
                case CUBE: c.rotate(0, PI / 100.0, 0);
                    break;
                case TETRAHEDRON: t.rotate(0, PI / 100.0, 0);
                    break;
                case SPHERE: s.rotate(0, PI / 100.0, 0);
                    break;
            }
            break;
        case 'c': 
            switch(shape) {
                case CUBE: c.rotate(0, 0, PI / 100.0);
                    break;
                case TETRAHEDRON: t.rotate(0, 0, PI / 100.0);
                    break;
                case SPHERE: s.rotate(0, 0, PI / 100.0);
                    break;
            }
            break;

    // only rotate for now

    //     case 'g': c.grow(10);
    //         break;
    //     case 's': c.shrink(10);
    //         break;
    //     case ',': c.move(0, -5, 0);
    //         break;
    //     case '.': c.move(0, 5, 0);
    //         break;
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
    int x_translate = x - 250;
    int y_translate = 250 - y;
    if (cube_button.hover(x_translate, y_translate) && state == GLUT_DOWN ) {
        cout << "cube" << endl;
        cube_button.on();
        tetrahedron_button.off();
        sphere_button.off();

        shape = CUBE;

    } else if (tetrahedron_button.hover(x_translate, y_translate) && state == GLUT_DOWN ) {
        cout << "tetrahedron" << endl;
        tetrahedron_button.on();
        cube_button.off();
        sphere_button.off();

        shape = TETRAHEDRON;
        
    } else if (sphere_button.hover(x_translate, y_translate) && state == GLUT_DOWN ) {
        cout << "sphere" << endl;
        sphere_button.on();
        cube_button.off();
        tetrahedron_button.off();

        shape = SPHERE;
    }

    
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
