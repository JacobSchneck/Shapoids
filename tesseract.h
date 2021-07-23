#ifndef INC_4D_GRAPHICS_TESSERACT_H
#define INC_4D_GRAPHICS_TESSERACT_H

#include "points.h"

#include <vector>

typedef point4D point;

class Tesseract {
	private:
		point center;
		unsigned int edge_length;
		std::vector<point> corners;

		// private helper methods;
		void reset_corners();
		void draw_point(const point &p) const;
	
	public: 
		// constructors
		Tesseract();
		Tesseract(point center, unsigned int edge_length);

		// draw the tesseract
		void draw() const;

		// rotate the tesseract
		void rotate(double theta_x, double theta_y, double theta_z, double theta_w);
};

#endif