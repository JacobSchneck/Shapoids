#include <math.h>
#include "button.h"
#include <iostream>

using namespace std;

/********************** Public methods *************************/
Button::Button() {
	center = {0, 0, 0};
	content = "Button";
	isOn = false;
	edge_length = 30;
}

Button::Button(string content, point center) {
	this -> center = center;
	this -> content = content;
	isOn = false;
	edge_length = 30;
}

// void Button::onClick() {
// 	isOn = isOn ? false : true;
// }

void Button::on() {
	isOn = true;
}

void Button::off() {
	isOn = false;
}

void Button::draw(Shape shape)  {
	glBegin(GL_QUADS);
	isOn ? glColor3f(.8, .8, .8) : glColor3f(1, 1, 1);
   glVertex3f(center.x + (edge_length ), center.y + (edge_length / 2.0), center.z + (edge_length / 2.0));
   glVertex3f(center.x - (edge_length ), center.y + (edge_length / 2.0), center.z + (edge_length / 2.0));
   glVertex3f(center.x - (edge_length ), center.y - (edge_length / 2.0), center.z + (edge_length / 2.0));
   glVertex3f(center.x + (edge_length ), center.y - (edge_length / 2.0), center.z + (edge_length / 2.0));
	glEnd();

	double size = edge_length / 2.0;
	switch(shape) {
		case CUBE: 
			glBegin(GL_QUADS);
			glColor3f(0, 0, 1);
			glVertex3f(center.x + (size / 2.0 ), center.y + (size / 2.0), center.z + (size / 2.0));
			glVertex3f(center.x - (size / 2.0 ), center.y + (size / 2.0), center.z + (size / 2.0));
			glVertex3f(center.x - (size / 2.0 ), center.y - (size / 2.0), center.z + (size / 2.0));
			glVertex3f(center.x + (size / 2.0 ), center.y - (size / 2.0), center.z + (size / 2.0));
			glEnd();
			break;
		case TETRAHEDRON: 
			// cout << "Triangle" << endl;
			size = edge_length / 2.6;
			glBegin(GL_TRIANGLES);
			glColor3f(0, 0, 1);
			glVertex3f(center.x + sqrt(8/9.0)*size, center.y, center.z - (1/3.0)*size);
			glVertex3f(center.x - sqrt(2/9.0)*size, center.y + sqrt(2/3.0)*size, center.z - (1/3.0)*size);
			glVertex3f(center.x - sqrt(2/9.0)*size, center.y - sqrt(2/3.0)*size, center.z - (1/3.0)*size);
			glEnd();
			break;
		case SPHERE: 
			size = size / 1.5;
			// Draw circle as Triangle Fan
			glColor3f(0, 0, 1);
			glBegin(GL_TRIANGLE_FAN);
			// Draw center point
			glVertex2i(center.x, center.y);
			// Draw points on edge of circle
			for (double i = 0; i < 2.0*PI+0.05; i += (2.0*PI)/360.0) {
				glVertex2i(center.x + (size * cos(i)),
								center.y + (size * sin(i)));
			}
			// End Triangle Fan
			glEnd();

			break;
	}

}

bool Button::hover(int x, int y) {
	// cout << "( " << x << ", " << y << ")" << endl;
	// cout << center.x - edge_length << " to " << center.x + edge_length << " | ";
	// cout << center.y - (edge_length / 2.0) << " to " << center.y + (edge_length / 2.0) << endl;

	if ( (x < center.x + edge_length && x > center.x - edge_length ) && (y < center.y + (edge_length  / 2.0) && y > center.y - (edge_length) / 2.0) ) {
		return true;
	}

	return false;
}