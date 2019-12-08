#pragma once

#include "utilities.h"

class Line; //fwd declaration


class Point {

public:
   Point();                     // Create uninitialized...
   Point(Number x, Number y);   // Create from (x,y)
   Number distance(Point point);  // Distance to another point
   Number distance(Line line);  // Distance to a line
   Number x();                  // get x-coordinate
   Number y();                  // get y-coordinate

private:
   Number the_x;                // x-coordinate
   Number the_y;                // y-coordinate
};