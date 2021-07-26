#ifndef INC_3D_GRAPHICS_TETRAHEDRON_H
#define INC_3D_GRAPHICS_TETRAHEDRON_H

#include "../points.h"

#include <vector>

typedef point3D point;

class Tetrahedron {
	private:
		point center;
		unsigned int edge_length;
		std::vector<point> corners;

		// private helper methods
		void reset_corners();
		void draw_point(const point &p) const;

	public:
		// Constructors
		Tetrahedron();
		Tetrahedron(point center, unsigned int edge_length);	

		// draw the tetrahedron
		void draw() const;

		// rotate the tetrahedron
		void rotate(double theta_x, double theta_y, double theta_z);
	
};

#endif