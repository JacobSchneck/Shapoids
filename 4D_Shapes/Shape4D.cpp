#include "Shape4D.h"
#include "../graphics.h"
#include <math.h>
using namespace std;

/****************** Private helper methods *******************/
void Shape4D::draw_vertex(const point4D &p) const {
	double distance = 2*edge_length;
	double w = distance / (distance - p.w); // projection scaler

	point3D projected_3D = {p.x * w, p.y * w, p.z * w}; // project the 4D into 3D space with scaler
	glVertex3f(projected_3D.x, projected_3D.y, projected_3D.z);
}

/********************** Public methods *************************/
Shape4D::Shape4D() {
	edge_length = 50;
}

Shape4D::Shape4D(unsigned int edge_length) {
	this->edge_length = edge_length;
}

Shape4D::~Shape4D() {}

