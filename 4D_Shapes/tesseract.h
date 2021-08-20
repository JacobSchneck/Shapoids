#ifndef TESSERACT_H
#define TESSERACT_H

#include "Shape4D.h"

#include <vector>

class Tesseract: public Shape4D {
	private:
		// override method
		// unsigned int tess_idx[32][2] {
		// 	// outer cube
		// 	{0, 1},
		// 	{0, 2},
		// 	{0, 4},
		// 	{1, 3},
		// 	{1, 5},
		// 	{2, 3},
		// 	{2, 6},
		// 	{3, 7},
		// 	{4, 5},
		// 	{4, 6},
		// 	{5, 7},
		// 	{6, 7},

		// 	// inner cube
		// 	{8, 9},
		// 	{8, 10},
		// 	{8, 12},
		// 	{9, 11},
		// 	{9, 13},
		// 	{10, 11},
		// 	{10, 14},
		// 	{11, 15},
		// 	{12, 13},
		// 	{12, 14},
		// 	{13, 15},
		// 	{14, 15},

		// 	// cube 3
		// 	{0, 8},
		// 	{1, 9},
		// 	{2, 10},
		// 	{3, 11},

		// 	// cube 4
		// 	{4, 12},
		// 	{5, 13},
		// 	{6, 14},
		// 	{7, 15}
		// };

		// std::vector<point4D> verticies;
		void construct_verticies() override;
		void construct_edges() override;

	public:
		Tesseract();
		~Tesseract();

		// void draw() const override;
		// void rotate(const rotation4D &rot_mat) override; 
};

#endif