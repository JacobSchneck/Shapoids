/*
*
* ------------- PLAY GROUND FOR SHAPES AND STUFF ---------------------
*
*/

#include "../graphics.h"
#include "../4D_Shapes/tesseract.h"
#include "../4D_Shapes/pentachoron.h"
#include "../points.h"

#include <math.h>
#include <iostream>
#include <vector>
#include <memory>


using namespace std;

int wd; // window

vector<point3D> cube;
vector<point4D> tesseract;
unsigned int tess_idx[32][2] {
	// outer cube
	{0, 1},
	{0, 2},
	{0, 4},
	{1, 3},
	{1, 5},
	{2, 3},
	{2, 6},
	{3, 7},
	{4, 5},
	{4, 6},
	{5, 7},
	{6, 7},

	// inner cube
	{8, 9},
	{8, 10},
	{8, 12},
	{9, 11},
	{9, 13},
	{10, 11},
	{10, 14},
	{11, 15},
	{12, 13},
	{12, 14},
	{13, 15},
	{14, 15},

	// cube 3
	{0, 8},
	{1, 9},
	{2, 10},
	{3, 11},

	// cube 4
	{4, 12},
	{5, 13},
	{6, 14},
	{7, 15}
}; 

vector<point3D> tetrahedron;
vector<point4D> pentachoron;
unsigned int  pent_idx[19][2] {
	{0, 1},
	{0, 2},
	{0, 3},
	{0, 4},
	{1, 2},
	{1, 3},
	{1, 4},
	{2, 3},
	{2, 4},
	{3, 4}
};

auto tess = Tesseract();
auto pent = Pentachoron();

GLdouble width, height;
void init() {
	width = 500;
	height = 500;

	// tess = Tesseract();

	// write a cube and tesseract
	{
	cube.resize(8);
	{
	cube[0] = {100, 100, 100};
	cube[1] = {100, 100, -100};
	cube[2] = {100, -100, 100};
	cube[3] = {100, -100, -100};
	cube[4] = {-100, 100, 100};
	cube[5] = {-100, 100, -100};
	cube[6] = {-100, -100, 100};
	cube[7] = {-100, -100, -100};
	}

	tesseract.resize(16);
	{
	tesseract[0] = { 50,  50,  50,  50};
	tesseract[1] = { 50,  50, -50,  50};
	tesseract[2] = { 50, -50,  50,  50};
	tesseract[3] = { 50, -50, -50,  50};
	tesseract[4] = {-50,  50,  50,  50};
	tesseract[5] = {-50,  50, -50,  50};
	tesseract[6] = {-50, -50,  50,  50};
	tesseract[7] = {-50, -50, -50,  50};

	tesseract[8] =  { 50,  50,  50, -50};
	tesseract[9] =  { 50,  50, -50, -50};
	tesseract[10] = { 50, -50,  50, -50};
	tesseract[11] = { 50, -50, -50, -50};
	tesseract[12] = {-50,  50,  50, -50};
	tesseract[13] = {-50,  50, -50, -50};
	tesseract[14] = {-50, -50,  50, -50};
	tesseract[15] = {-50, -50, -50, -50};
	}

	}

	// write a tetrahedron and a pentachoron
	{
	// writing a tetrahedron and pentachoron
	tetrahedron.resize(4);
	tetrahedron[0] = {sqrt(8/9.0)*100, 0,  (1/3.0)*100};
	tetrahedron[1] = {-sqrt(2/9.0)*100,  sqrt(2/3.0)*100,  (1/3.0)*100};
	tetrahedron[2] = {-sqrt(2/9.0)*100, -sqrt(2/3.0)*100,  (1/3.0)*100};
	tetrahedron[3] = {0, 0,  100};

	pentachoron.resize(5);
	pentachoron[0] = {50, 50, 50, -50/sqrt(5)};
	pentachoron[1] = {50, -50, -50, -50/sqrt(5)};
	pentachoron[2] = {-50, 50, -50, -50/sqrt(5)};
	pentachoron[3] = {-50, -50, 50, -50/sqrt(5)};
	pentachoron[4] = {0, 0, 0, 200/sqrt(5)};
	}

}

void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat lineWidthRange[2] = {0.0f, 0.0f};
    glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);
    gluLookAt(3.0, 4.0, 7.0,  // eye position
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

void draw_vertex(const point3D &p) {
	glVertex3f(p.x, p.y, p.z);
}

void draw_vertex(const point4D &p) {
	double distance =  200;
	double w = distance / (distance - p.w); // projection scaler

	point3D projected_3D = {p.x * w, p.y * w, p.z * w}; // project the 4D into 3D space with scaler
	draw_vertex(projected_3D);
}

void draw_cube() {
	glLineWidth(2.0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);

	draw_vertex(cube[0]);
	draw_vertex(cube[1]);

	draw_vertex(cube[0]);
	draw_vertex(cube[2]);

	draw_vertex(cube[0]);
	draw_vertex(cube[4]);

	draw_vertex(cube[1]);
	draw_vertex(cube[3]);

	draw_vertex(cube[1]);
	draw_vertex(cube[5]);

	draw_vertex(cube[2]);
	draw_vertex(cube[3]);

	draw_vertex(cube[2]);
	draw_vertex(cube[6]);

	draw_vertex(cube[3]);
	draw_vertex(cube[7]);

	draw_vertex(cube[4]);
	draw_vertex(cube[5]);

	draw_vertex(cube[4]);
	draw_vertex(cube[6]);

	draw_vertex(cube[5]);
	draw_vertex(cube[7]);

	draw_vertex(cube[6]);
	draw_vertex(cube[7]);

	glEnd();
}

void draw_tesseract() {
	glLineWidth(2.0);
	glPointSize(5.0);

	glBegin(GL_LINES);
	for (auto &vec : tess_idx) {
		glColor3f(1.0, 0.0, 1.0);
		draw_vertex(tesseract[vec[0]]);
		glColor3f(1.0, 1.0, 0.0);
		draw_vertex(tesseract[vec[1]]);
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < tesseract.size(); ++i) {
		draw_vertex(tesseract[i]);
	}
	glEnd();
}

void draw_tetrahedron() {
	glColor3f(1.0, 1.0, 1.0);

	glLineWidth(2.0);
	glBegin(GL_LINES);

	// edge 1
	draw_vertex(tetrahedron[0]);
	draw_vertex(tetrahedron[1]);

	// edge 2... 
	draw_vertex(tetrahedron[0]);
	draw_vertex(tetrahedron[2]);

	draw_vertex(tetrahedron[0]);
	draw_vertex(tetrahedron[3]);

	draw_vertex(tetrahedron[1]);
	draw_vertex(tetrahedron[2]);

	draw_vertex(tetrahedron[1]);
	draw_vertex(tetrahedron[3]);

	draw_vertex(tetrahedron[2]);
	draw_vertex(tetrahedron[3]);

	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	draw_vertex(tetrahedron[0]);
	draw_vertex(tetrahedron[1]);
	draw_vertex(tetrahedron[2]);
	draw_vertex(tetrahedron[3]);
	glEnd();
}

void draw_pentachoron() {
	glLineWidth(2.0);
	glPointSize(5.0);

	glBegin(GL_LINES);
	for (auto &vec : pent_idx) {
		glColor3f(1.0, 0.0, 1.0);
		draw_vertex(pentachoron[vec[0]]);
		glColor3f(1.0, 1.0, 0.0);
		draw_vertex(pentachoron[vec[1]]);
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < pentachoron.size(); ++i) {
		draw_vertex(pentachoron[i]);
	}
	glEnd();
}

void rotate(vector<point4D> &shape_4D, vector<vector<double>> &rot_mat) {
	for (point4D &p : shape_4D) {
		p.x = rot_mat[0][0]*p.x + rot_mat[0][1]*p.y + rot_mat[0][2]*p.z + rot_mat[0][3]*p.w;
		p.y = rot_mat[1][0]*p.x + rot_mat[1][1]*p.y + rot_mat[1][2]*p.z + rot_mat[1][3]*p.w;
		p.z = rot_mat[2][0]*p.x + rot_mat[2][1]*p.y + rot_mat[2][2]*p.z + rot_mat[2][3]*p.w;
		p.w = rot_mat[3][0]*p.x + rot_mat[3][1]*p.y + rot_mat[3][2]*p.z + rot_mat[3][3]*p.w;
	}
}

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
	// draw_cube();

	// tess.draw();
	pent.draw();

	// draw_tesseract(); // works !!
	// draw_pentachoron();

	// draw_tetrahedron();
	// draw_axes();
	glFlush();  // Render now
}

void kbd(unsigned char key, int x, int y) {
	// escape
	if (key == 27) {
		glutDestroyWindow(wd);
		exit(0);
	}

	double d_theta = PI / 100;

	// xy plane rotation
	vector<vector<double>> theta_xy = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, cos(d_theta), -sin(d_theta),},
		{0, 0, sin(d_theta), cos(d_theta), }
	};

	// xz plane rotation
	vector<vector<double>> theta_xz = {
		{1, 				0, 0, 				0},
		{0, cos(d_theta), 0, -sin(d_theta)},
		{0, 				0, 1, 			  0,},
		{0, sin(d_theta), 0,  cos(d_theta)}
	};

	//  yz plane rotation
	vector<vector<double>> theta_yz = {
		{cos(d_theta), 0, 0, -sin(d_theta)},
		{0, 1, 0, 0},
		{0, 0, 1, 0,},
		{sin(d_theta), 0, 0, cos(d_theta), }
	};


	// xy plane rotation
	double theta_xy_arr[4][4] {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, cos(d_theta), -sin(d_theta),},
		{0, 0, sin(d_theta), cos(d_theta), }
	};

	// xz plane rotation
	double theta_xz_arr[4][4] {
		{1, 				0, 0, 				0},
		{0, cos(d_theta), 0, -sin(d_theta)},
		{0, 				0, 1, 			  0,},
		{0, sin(d_theta), 0,  cos(d_theta)}
	};

	//  yz plane rotation
	double theta_yz_arr[4][4] {
		{cos(d_theta), 0, 0, -sin(d_theta)},
		{0, 1, 0, 0},
		{0, 0, 1, 0,},
		{sin(d_theta), 0, 0, cos(d_theta), }
	};

	// double theta_xy[4][4];
	// std:copy(theta_xy.begin(), theta_xy.end(), arr[0])

	switch(key) {
		case 'x': 
			rotate(tesseract, theta_xy);
			rotate(pentachoron, theta_xy);
			tess.rotate(theta_xy_arr);
			pent.rotate(theta_xy_arr);
			break;
		case 'z':   
			rotate(tesseract, theta_xz);
			rotate(pentachoron, theta_xz);
			tess.rotate(theta_xz_arr);
			pent.rotate(theta_xz_arr);
			break;
		case 'c': 
			rotate(tesseract, theta_yz);
			rotate(pentachoron, theta_yz);
			tess.rotate(theta_yz_arr);
			pent.rotate(theta_yz_arr);
			break;
	}

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
	glutPostRedisplay();
}

void cursor(int x, int y) {
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

int main(int argc, char** argv) {

	init(); // set up zone
	
	glutInit(&argc, argv);          // Initialize GLUT
	
	glutInitDisplayMode(GLUT_RGBA);
	
	glutInitWindowSize((int)width, (int)height);
	glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
	/* create the window and store the handle to it */
	wd = glutCreateWindow("4D Graphics!" /* title */ );
	
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