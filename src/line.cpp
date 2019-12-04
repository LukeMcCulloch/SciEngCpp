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

Number Line::parallelism_tolerance = .01745; // 1 deg in radians

Point Line::intersect(Line line) {
   // Intersect with line.
   // if angle between the two is < tol, then point at infinity
   // here we check the square of the sum of the angle
   // for tol <<, sin theta = theta
   Number det = a * line.b - line.a * b;
   Number sinsq = (det * det) / ((a*a + b*b) * (line.a*line.a +line.b*line.b) ) ;
   if (sinsq < parallelism_tolerance * parallelism_tolerance) {
      return Point(FLT_MAX, FLT_MAX);   // point at infinity (FLT_MAX from float.h)
   }
   else{
      return Point( (b*line.c - line.b*c)/det ,
                     (c*line.a - line.c*a) / det);
   }
}