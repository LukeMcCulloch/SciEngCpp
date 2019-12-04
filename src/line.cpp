#include "line.h"
#include "point.h"

Line::Line(Point p1, Point p2) {
   //construct a line through points p1 and p2
   if (p1.x() == p2.x()) {   // the line is vertical
      a = 1;
      b = 0;
      c = -p1.x();
   }
   else {                    // nonvertical line
      a = p2.y() - p1.y();
      b = p2.x() - p1.x();
      c = p1.y() * p2.x() - p2.y() * p1.x();
   }
}

Number Line::distance(Point point) {
   // returns the distance from point to the line
   return abs(a * point.x() +b * point.y() + c)/sqrt(a*a + b*b);
}