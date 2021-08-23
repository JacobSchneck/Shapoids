
#include <math.h>
#include "tetrahedron.h"
#include "../graphics.h"
#include <iostream>

using namespace std;


/****************** Private helper methods *******************/
void Tetrahedron::reset_corners() {
	corners.clear();
	corners.resize(4);

	corners[0] = {center.x + sqrt(8/9.0)*edge_length, center.y, center.z - (1/3.0)*edge_length};
	corners[1] = {center.x - sqrt(2/9.0)*edge_length, center.y + sqrt(2/3.0)*edge_length, center.z - (1/3.0)*edge_length};
	corners[2] = {center.x - sqrt(2/9.0)*edge_length, center.y - sqrt(2/3.0)*edge_length, center.z - (1/3.0)*edge_length};
	corners[3] = {center.x, center.y, center.z + edge_length};

}

void Tetrahedron::draw_point(const point &p) const {
	glVertex3f(p.x, p.y, p.z);
}

/********************** Public methods *************************/
Tetrahedron::Tetrahedron() {
   center = {0, 0, 0};
   edge_length = 50;
   reset_corners();
}

Tetrahedron::Tetrahedron(point center, unsigned int edge_length) {
    this->center = center;
    this->edge_length = edge_length;
    reset_corners();
}

void Tetrahedron::draw() const {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(1, 1, 0);
	draw_point(corners[0]);
	draw_point(corners[1]);
	draw_point(corners[2]);

	glColor3f(1, 0, 1);
	draw_point(corners[1]);
	draw_point(corners[2]);
	draw_point(corners[3]);

	glColor3f(0, 1, 1);
	draw_point(corners[2]);
	draw_point(corners[3]);
	draw_point(corners[0]);

	glColor3f(1, 0, 0);
	draw_point(corners[3]);
	draw_point(corners[0]);
	draw_point(corners[1]);

	glEnd();
}
	

void Tetrahedron::rotate(double theta_x, double theta_y, double theta_z) {
    double old_x = 0, old_y = 0, old_z = 0;
    double center_x = center.x, center_y = center.y, center_z = center.z;

    // Rotate x
    for (point &p : corners) {
        old_y = p.y;
        old_z = p.z;
        p.y = old_y * cos(theta_x) - old_z * sin(theta_x);
        p.z = old_y * sin(theta_x) + old_z * cos(theta_x);
    }
    for (point &p : corners) {
        old_x = p.x;
        old_z = p.z;
        p.x = old_x * cos(theta_y) - old_z * sin(theta_y);
        p.z = old_x * sin(theta_y) + old_z * cos(theta_y);
    }
    for (point &p : corners) {
        old_x = p.x;
        old_y = p.y;
        p.x = old_x * cos(theta_z) - old_y * sin(theta_z);
        p.y = old_x * sin(theta_z) + old_y * cos(theta_z);
    }
}