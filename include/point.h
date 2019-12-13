#pragma once

#include "utilities.h"

class Line; //fwd declaration


class Point {

public:
   Point();                          // Create uninitialized...
   Point(Number x, Number y);        // Create from (x,y)
   Number distance(Point point);     // Distance to another point
   Number distance(Line line);       // Distance to a line
   Number x();                       // get x-coordinate
   Number y();                       // get y-coordinate
   Number angle(Point p1, Point p2); // page 116 
   Number dot(Point p1, Point p2);
   Number cross(Point p1, Point p2);

private:
   Number the_x;                // x-coordinate
   Number the_y;                // y-coordinate
};