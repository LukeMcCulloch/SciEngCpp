#include "point.h"
#include "line.h"

Point::Point() {
}

Point::Point(Number x, Number y) {
   the_x = x;
   the_y = y;
}

Number Point::distance(Point point) {
   Number x_diff = the_x - point.the_x;
   Number y_diff = the_y - point.the_y;
   return sqrt(x_diff * x_diff + y_diff * y_diff);
}

Number Point::distance(Line line) {
   return line.distance(*this);
}

Number Point::x() {return the_x;}
Number Point::y() {return the_y;}
