#include <math.h>
#include "sphere.h"
#include "graphics.h"
#include <iostream>

/****************** Private helper methods *******************/
void Sphere::construct_verticies() {

}

void Sphere::construct_sectors() {

}

/********************** Public methods *************************/
Sphere::Sphere() {
	center = {0, 0, 0};
	radius = 50;
	construct_verticies();
}

Sphere::Sphere(point center, unsigned int radius) {
	this -> center = center;
	this -> radius = radius;
	construct_verticies();
}