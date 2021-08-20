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

void Shape4D::draw() const {
	glLineWidth(2.0);
	glPointSize(5.0);

	glBegin(GL_LINES);
	for (auto &edge : edges) {
		glColor3f(1.0, 0.0, 1.0);
		draw_vertex(verticies[edge.to]);
		glColor3f(1.0, 1.0, 0.0);
		draw_vertex(verticies[edge.from]);
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < verticies.size(); ++i) {
		draw_vertex(verticies[i]);
	}
	glEnd();
}

void Shape4D::rotate(const rotation4D &rot_mat) {
	for (point4D &p : verticies) {
		p.x = rot_mat[0][0]*p.x + rot_mat[0][1]*p.y + rot_mat[0][2]*p.z + rot_mat[0][3]*p.w;
		p.y = rot_mat[1][0]*p.x + rot_mat[1][1]*p.y + rot_mat[1][2]*p.z + rot_mat[1][3]*p.w;
		p.z = rot_mat[2][0]*p.x + rot_mat[2][1]*p.y + rot_mat[2][2]*p.z + rot_mat[2][3]*p.w;
		p.w = rot_mat[3][0]*p.x + rot_mat[3][1]*p.y + rot_mat[3][2]*p.z + rot_mat[3][3]*p.w;
	}
}

