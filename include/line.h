#include "utilities.h"

class Point; //fwd declaration


class Line {

public:
   Line(Point p1, Point p2);                 // Line through two points
   Line(Point p, Number xDir, Number yDir);  // Line through p with tangent <xDir, yDir>
   Point intersect(Line line);               // Intersection with a line
   Number distance(Point point);             // Distance to a point

   static Number parallelism_tolerance;      // Smallest nonparallel angle (radians)

private:
   //ax + by + c = 0
   Number a;
   Number b;
   Number c;
};
