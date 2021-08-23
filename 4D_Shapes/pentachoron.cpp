#include <math.h>
#include <iostream>

#include "../graphics.h"
#include "pentachoron.h"

using namespace std;

/****************** Private helper methods *******************/
void Pentachoron::construct_verticies() {
	verticies.resize(5);
	verticies[0] = {edge_length, edge_length, edge_length, -edge_length/sqrt(5)};
	verticies[1] = {edge_length, -edge_length, -edge_length, -edge_length/sqrt(5)};
	verticies[2] = {-edge_length, edge_length, -edge_length, -edge_length/sqrt(5)};
	verticies[3] = {-edge_length, -edge_length, edge_length, -edge_length/sqrt(5)};
	verticies[4] = {0, 0, 0, 4*edge_length/sqrt(5)};
}

void Pentachoron::construct_edges() {
	edges.resize(10);
	edges[0] = {0, 1};
	edges[1] = {0, 2};
	edges[2] = {0, 3};
	edges[3] = {0, 4};
	edges[4] = {1, 2};
	edges[5] = {1, 3};
	edges[6] = {1, 4};
	edges[7] = {2, 3};
	edges[8] = {2, 4};
	edges[9] = {3, 4};
}

/********************** Public methods *************************/
Pentachoron::Pentachoron() : Shape4D() {
	cout << edge_length << endl;
	cout << "Calling Constructor" << endl;
	construct_verticies();
	construct_edges();
};
Pentachoron::~Pentachoron() {};