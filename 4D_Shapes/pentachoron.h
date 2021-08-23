#ifndef PENTACHORON_H
#define PENTACHORON_H

#include "Shape4D.h"
#include <vector>

class Pentachoron: public Shape4D {
	private: 
		void construct_verticies() override;
		void construct_edges() override;
	public:
		Pentachoron();
		~Pentachoron();
};

#endif