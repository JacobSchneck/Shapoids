#include <math.h>
#include "button.h"
#include "graphics.h"
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

void Button::onClick() {
	isOn = isOn ? false : true;
}

void Button::draw()  {
	glBegin(GL_QUADS);
	isOn ? glColor3f(.8, .8, .8) : glColor3f(1, 1, 1);
   glVertex3f(center.x + (edge_length ), center.y + (edge_length / 2.0), center.z + (edge_length / 2.0));
   glVertex3f(center.x - (edge_length ), center.y + (edge_length / 2.0), center.z + (edge_length / 2.0));
   glVertex3f(center.x - (edge_length ), center.y - (edge_length / 2.0), center.z + (edge_length / 2.0));
   glVertex3f(center.x + (edge_length ), center.y - (edge_length / 2.0), center.z + (edge_length / 2.0));
	glEnd();
}