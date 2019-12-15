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

Number Point::x()  {return the_x;}
Number Point::y()  {return the_y;}
Number Point::x() const {return the_x;}
Number Point::y() const {return the_y;}



Number dot( const Point& p1,  const Point& p2) {
   Number x21 = p1.x();
   Number y21 = p1.y();
   
   Number x22 = p2.x();
   Number y22 = p2.y();

   return x21*x22 + y21*y22;

}

Number cross( const Point& p1,  const Point& p2) {
   Number x21 = p1.x();
   Number y21 = p1.y();
   
   Number x22 = p2.x();
   Number y22 = p2.y();

   return x21*y22 - y21*x22;

}

Number Point::angle( const Point& p1,  const Point& p3) {
   // *this is p2, the point about which 
   //  the rays p1 and p3 form an angle
   Number x21 = p1.the_x - the_x;
   Number y21 = p1.the_y - the_y;
   Point v21 = Point(x21,y21);

   Number x23 = p3.the_x - the_x;
   Number y23 = p3.the_y - the_y;
   Point v23 = Point(x23,y23);

   return atan2( cross(v21,v21), dot(v21,v23) );
}


std::ostream& operator<<(std::ostream& ostream, const Point& p) {
   ostream <<  p.the_x << p.the_y << "";
   return ostream;
}