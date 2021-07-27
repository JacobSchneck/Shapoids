#include "points.h"
#include <string>

typedef point3D point;

class Button {
	private: 
		point center;
		std::string content;
		bool isOn;
		unsigned int edge_length;

	public:
		// constructors
		Button();

		Button(std::string content, point center);

		void on();

		void off();

		// draw
		void draw();

		// check if mouse hovers over button;
		bool hover(int x, int y);
};