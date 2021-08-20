#include <math.h>
#include <iostream>

#include "../graphics.h"
#include "tesseract.h"

using namespace std;

/****************** Private helper methods *******************/
void Tesseract::construct_verticies() {
	verticies.clear();
	verticies.resize(15);

	verticies[0] = { edge_length,  edge_length,  edge_length,  edge_length};
	verticies[1] = { edge_length,  edge_length, -edge_length,  edge_length};
	verticies[2] = { edge_length, -edge_length,  edge_length,  edge_length};
	verticies[3] = { edge_length, -edge_length, -edge_length,  edge_length};
	verticies[4] = {-edge_length,  edge_length,  edge_length,  edge_length};
	verticies[5] = {-edge_length,  edge_length, -edge_length,  edge_length};
	verticies[6] = {-edge_length, -edge_length,  edge_length,  edge_length};
	verticies[7] = {-edge_length, -edge_length, -edge_length,  edge_length};

	verticies[8] =  { edge_length,  edge_length,  edge_length, -edge_length};
	verticies[9] =  { edge_length,  edge_length, -edge_length, -edge_length};
	verticies[10] = { edge_length, -edge_length,  edge_length, -edge_length};
	verticies[11] = { edge_length, -edge_length, -edge_length, -edge_length};
	verticies[12] = {-edge_length,  edge_length,  edge_length, -edge_length};
	verticies[13] = {-edge_length,  edge_length, -edge_length, -edge_length};
	verticies[14] = {-edge_length, -edge_length,  edge_length, -edge_length};
	verticies[15] = {-edge_length, -edge_length, -edge_length, -edge_length};
}
/********************** Public methods *************************/
Tesseract::Tesseract() : Shape4D() {
	// cout << "HI" << endl;
	construct_verticies();
};
Tesseract::~Tesseract() {};

void Tesseract::draw() const {
	// glLineWidth(2.0);
	// glPointSize(5.0);

	// glBegin(GL_LINES);
	// for (auto &vec : tess_idx) {
	// 	glColor3f(1.0, 0.0, 1.0);
	// 	draw_vertex(verticies[vec[0]]);
	// 	glColor3f(1.0, 1.0, 0.0);
	// 	draw_vertex(verticies[vec[1]]);
	// }
	// glEnd();

	// glColor3f(1.0, 1.0, 1.0);
	// glBegin(GL_POINTS);
	// for (int i = 0; i < verticies.size(); ++i) {
	// 	draw_vertex(verticies[i]);
	// }
	// glEnd();
}

void Tesseract::rotate(const rotation4D &rot_mat) {
	// for (point4D &p : verticies) {
	// 	p.x = rot_mat[0][0]*p.x + rot_mat[0][1]*p.y + rot_mat[0][2]*p.z + rot_mat[0][3]*p.w;
	// 	p.y = rot_mat[1][0]*p.x + rot_mat[1][1]*p.y + rot_mat[1][2]*p.z + rot_mat[1][3]*p.w;
	// 	p.z = rot_mat[2][0]*p.x + rot_mat[2][1]*p.y + rot_mat[2][2]*p.z + rot_mat[2][3]*p.w;
	// 	p.w = rot_mat[3][0]*p.x + rot_mat[3][1]*p.y + rot_mat[3][2]*p.z + rot_mat[3][3]*p.w;
	// }
}

