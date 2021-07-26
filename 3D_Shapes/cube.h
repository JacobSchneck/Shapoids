#ifndef INC_3D_GRAPHICS_CUBE_H
#define INC_3D_GRAPHICS_CUBE_H

#include "../points.h"

#include <vector>

typedef point3D point;

class Cube {
private:
    point center;
    unsigned int edge_length;
    std::vector<point> corners;

    // Private helper methods
    void reset_corners();
    void draw_point(const point &p) const;

public:

    // Constructors
    Cube();
    Cube(point center, unsigned int edge_length);

    // Draw the cube
    void draw() const;

    // Rotate the cube
    void rotate(double theta_x, double theta_y, double theta_z);

    // Move the cube
    void move(double delta_x, double delta_y, double delta_z);

    // Grow the cube
    void grow(double percent);

    // Shrink the cube
    void shrink(double percent);
};


#endif //INC_3D_GRAPHICS_CUBE_H
