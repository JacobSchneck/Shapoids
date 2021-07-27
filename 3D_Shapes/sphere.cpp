#include <math.h>
#include "sphere.h"
#include "../graphics.h"
#include <iostream>

using namespace std;

/****************** Private helper methods *******************/
void Sphere::construct_verticies() {
	vector<double> lon;
	vector<double> lat;
	lon.resize(num_points);
	lat.resize(num_points);

	lon[0] = -M_PI;
	double lon_step = 2*M_PI / num_points;
	lat[0] = -M_PI;
	double lat_step = 2*M_PI / num_points;

	for (int i = 1; i < num_points + 1; i++) {
		lon[i] = lon[i - 1] + lon_step;
		lat[i] = lat[i - 1] + lat_step;
	}

	// clear verticies 
	for (auto &vec : verticies) {
		vec.clear();
	}
	verticies.clear();

	// resize verticies
	verticies.resize(num_points + 1);
	for (auto &vec : verticies) {
		vec.resize(num_points + 1);
	}

	for (int i = 0; i < num_points + 1; i++ ) {
		for( int j = 0; j < num_points + 1; j++) {		
			double x = radius * cos(lon[i]) * sin(lat[j]);
			double y = radius * sin(lon[i]) * sin(lat[j]);
			double z = radius * cos(lat[j]);
			verticies[i][j] = {x, y, z};
		}
	}
}


/********************** Public methods *************************/
Sphere::Sphere() {
	center = {0, 0, 0};
	radius = 100;
	num_points = 10;
	construct_verticies();
}

Sphere::Sphere(point center, unsigned int radius, unsigned int num_points) {
	this -> center = center;
	this -> radius = radius;
	this -> num_points = num_points;
	construct_verticies();
}

void Sphere::draw() const {
	for (int i = 0; i < num_points; i++ ) {
		glBegin(GL_TRIANGLE_STRIP);
		for( int j = 0; j < num_points + 1; j++) {		
			auto v1 = verticies[i][j]; 
			auto v2 = verticies[i + 1][j];

			glVertex3f(v1.x, v1.y, v1.z);
			glVertex3f(v2.x, v2.y, v2.z);
		}
	}
	glEnd();

}

void Sphere::rotate(double theta_x, double theta_y, double theta_z) {
    double old_x = 0, old_y = 0, old_z = 0;
    double center_x = center.x, center_y = center.y, center_z = center.z;

    // Rotate x
	for (auto &vec : verticies) {
		for (point &p : vec) {
			old_y = p.y;
			old_z = p.z;
			p.y = old_y * cos(theta_x) - old_z * sin(theta_x);
			p.z = old_y * sin(theta_x) + old_z * cos(theta_x);
		}
	}

	for (auto &vec : verticies) {
		for (point &p : vec) {
        old_x = p.x;
        old_z = p.z;
        p.x = old_x * cos(theta_y) - old_z * sin(theta_y);
        p.z = old_x * sin(theta_y) + old_z * cos(theta_y);
		}
	}
	 
	for (auto &vec : verticies) {
		for (point &p : vec) {
        old_x = p.x;
        old_y = p.y;
        p.x = old_x * cos(theta_z) - old_y * sin(theta_z);
        p.y = old_x * sin(theta_z) + old_y * cos(theta_z);
		}
	}
}