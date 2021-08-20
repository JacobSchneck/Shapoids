#include <math.h>
#include <iostream>

#include "../graphics.h"
#include "tesseract.h"

using namespace std;

/****************** Private helper methods *******************/
void Tesseract::construct_verticies() {
	cout << "Constructing Verticies" << endl;

	// verticies.clear();

	verticies.push_back({ edge_length,  edge_length,  edge_length,  edge_length});
	verticies.push_back({ edge_length,  edge_length, -edge_length,  edge_length});
	verticies.push_back({ edge_length, -edge_length,  edge_length,  edge_length});
	verticies.push_back({ edge_length, -edge_length, -edge_length,  edge_length});
	verticies.push_back({-edge_length,  edge_length,  edge_length,  edge_length});
	verticies.push_back({-edge_length,  edge_length, -edge_length,  edge_length});
	verticies.push_back({-edge_length, -edge_length,  edge_length,  edge_length});
	verticies.push_back({-edge_length, -edge_length, -edge_length,  edge_length});

	verticies.push_back({ edge_length,  edge_length,  edge_length, -edge_length});
	verticies.push_back({ edge_length,  edge_length, -edge_length, -edge_length});
	verticies.push_back({ edge_length, -edge_length,  edge_length, -edge_length});
	verticies.push_back({ edge_length, -edge_length, -edge_length, -edge_length});
	verticies.push_back({-edge_length,  edge_length,  edge_length, -edge_length});
	verticies.push_back({-edge_length,  edge_length, -edge_length, -edge_length});
	verticies.push_back({-edge_length, -edge_length,  edge_length, -edge_length});
	verticies.push_back({-edge_length, -edge_length, -edge_length, -edge_length});
}

void Tesseract::construct_edges() {
	// outer cube
	edges.push_back({0, 1});
	edges.push_back({0, 2});
	edges.push_back({0, 4});
	edges.push_back({1, 3});
	edges.push_back({1, 5});
	edges.push_back({2, 3});
	edges.push_back({2, 6});
	edges.push_back({3, 7});
	edges.push_back({4, 5});
	edges.push_back({4, 6});
	edges.push_back({5, 7});
	edges.push_back({6, 7});

	// inner cube
	edges.push_back({8, 9});
	edges.push_back({8, 10});
	edges.push_back({8, 12});
	edges.push_back({9, 11});
	edges.push_back({9, 13});
	edges.push_back({10, 11});
	edges.push_back({10, 14});
	edges.push_back({11, 15});
	edges.push_back({12, 13});
	edges.push_back({12, 14});
	edges.push_back({13, 15});
	edges.push_back({14, 15});

	// cube 3
	edges.push_back({0, 8});
	edges.push_back({1, 9});
	edges.push_back({2, 10});
	edges.push_back({3, 11});

	// cube 4
	edges.push_back({4, 12});
	edges.push_back({5, 13});
	edges.push_back({6, 14});
	edges.push_back({7, 15});
}

/********************** Public methods *************************/
Tesseract::Tesseract() : Shape4D() {
	cout << edge_length << endl;
	cout << "Calling Constructor" << endl;
	construct_verticies();
	construct_edges();
};
Tesseract::~Tesseract() {};

