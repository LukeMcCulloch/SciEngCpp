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

Point::Point() {
}

Point::Point(Number x, Number y) {
   the_x = x;
   the_y = y;
}

Number Point::x() {return the_x;}
Number Point::y() {return the_y;}

Number Point::distance(Point point) {
   Number x_diff = the_x - point.the_x;
   Number y_diff = the_y - point.the_y;
   return sqrt(x_diff * x_diff + y_diff * y_diff);
}

//Number Point::distance(Line line) {return line.distance(*this);}