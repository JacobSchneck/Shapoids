#ifndef INC_3D_GRAPHICS_SPHERE_H
#define INC_3D_GRAPHICS_SPHERE_H

#include "points.h"

#include <vector>

// constants (to use #define or not to)
// const double PI = 3.1415926f;
// const double H_ANGLE = PI / 180 * 72
// const 

typedef point3D point;

class Sphere {
	private:
		point center;
		unsigned int radius;
		std::vector<point> verticies; // verticies
		std::vector<point> sectors; // triangle component used to construct sphere maybe

		// private helper methods
		void construct_verticies();
		void construct_sectors(); // maybe
		void draw_point(const point &p) const; // draw the verticies
		void draw_sector(const point &p1, const point &p2, const point &p3);

	public:

		// Constructors
		Sphere();
		Sphere(point center, unsigned int radius);

		// Draw the Sphere
		void draw() const;

		// Rotate the Sphere
		void rotate(double theta_x, double theta_y, double theta_z);

};

#endif