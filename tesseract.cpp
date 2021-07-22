#include <math.h>
#include <iostream>

#include "graphics.h"
#include "tesseract.h"

/****************** Private helper methods *******************/
void Tesseract::reset_corners() {
	corners.clear();
	corners.resize(16);
	// TODO: Big Painful corner initialization;

	// I'm clever
	char X_SIGN[] = {'p', 'p', 'p', 'p','p', 'p', 'p', 'p', 'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n'};
	char Y_SIGN[] = {'p', 'p', 'p', 'p','n', 'n', 'n', 'n', 'p', 'p', 'p', 'p', 'n', 'n', 'n', 'n'};
	char Z_SIGN[] = {'p', 'p', 'n', 'n','p', 'p', 'n', 'n', 'p', 'p', 'n', 'n', 'p', 'p', 'n', 'n'};
	char W_SIGN[] = {'p', 'n', 'p', 'n','p', 'n', 'p', 'n', 'p', 'n', 'p', 'n', 'p', 'n', 'p', 'n'};

	for (int i = 0; i < corners.size(); i++) {
		double x_val = X_SIGN[i] == 'p' ? center.x + (edge_length / 2.0) : center.x - (edge_length / 2.0);
		double y_val = Y_SIGN[i] == 'p' ? center.y + (edge_length / 2.0) : center.y - (edge_length / 2.0);
		double z_val = Z_SIGN[i] == 'p' ? center.z + (edge_length / 2.0) : center.z - (edge_length / 2.0);
		double w_val = W_SIGN[i] == 'p' ? center.w + (edge_length / 2.0) : center.w - (edge_length / 2.0);

		corners[i] = {x_val, y_val, z_val, w_val};
	}
}

void Tesseract::draw_point(const point &p) const {
	glVertex4d(p.x, p.y, p.z, p.w);
}
/********************** Public methods *************************/
Tesseract::Tesseract() {
	center = {0, 0, 0, 0};
	edge_length = 50;
	reset_corners();
}

Tesseract::Tesseract(point center, unsigned int edge_length) {
	this -> center = center;
	this -> edge_length = edge_length;
	reset_corners();
}

void Tesseract::draw() const {
	glBegin(GL_QUADS);
	// TODO: More big Pain,  draw each face of tesseract using draw_point

	// 24 faces from 16 vertices ugh
	
	

	glEnd();
}

void Tesseract::rotate(double theta_x, double theta_y, double theta_z, double theta_w) {
	// TODO: Write rotation function (maybe TDD is in order)
}
