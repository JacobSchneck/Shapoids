#ifndef TESSERACT_H
#define TESSERACT_H

#include "Shape4D.h"

#include <vector>

class Tesseract: public Shape4D {
	private:
		void construct_verticies() override;
		void construct_edges() override;

	public:
		Tesseract();
		~Tesseract();
};

#endif