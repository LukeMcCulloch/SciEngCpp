#include <cassert>
#include <iostream>
#include <limits>
#include <cmath>


#include "utilities.h"
#include "point.h"
#include "line.h"
#include "SimpleArray.h"
#include "SimpleArray.cpp" 

typedef Point Node;        //Node class that behaves like a point

class Element {

public:
   int operator[](int i) const;
   int numNodes()        const;
   friend istream& operator>>(istream&, Element&);
private:

}