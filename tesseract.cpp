#include <math.h>
#include <iostream>

#include "graphics.h"
#include "tesseract.h"

/****************** Private helper methods *******************/
void Tesseract::reset_corners() {
	corners.clear();
	corners.resize(16);
	// TODO: Big Painful corner initialization;

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

	glEnd();
}

void Tesseract::rotate(double theta_x, double theta_y, double theta_z, double theta_w) {
	// TODO: Write rotation function (maybe TDD is in order)
}
