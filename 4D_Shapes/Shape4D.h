#ifndef INC_4D_GRAPHICS_TESSERACT_H
#define INC_4D_GRAPHICS_TESSERACT_H

#include "../points.h"
#include <vector>

typedef double rotation4D[4][4]; // rotation matrix for 4th dimension

struct Edge {
	unsigned int to;
	unsigned int from;
};

class Shape4D {
	protected:
		double edge_length;
		std::vector<point4D> verticies;
		std::vector<Edge> edges;

		// helper methods
		virtual void construct_verticies() = 0; // unique to every 4D shape
		virtual void construct_edges() = 0; // unique to every 4D shape
		void draw_vertex(const point4D &p) const;

	public:
		Shape4D();
		explicit Shape4D(unsigned int edge_length);
		~Shape4D();

		// methods
		// virtual void draw() const = 0;
		// virtual void rotate(const rotation4D &rot_mat) = 0;
		void draw() const;
		void rotate(const rotation4D &rot_mat);
};

#endif