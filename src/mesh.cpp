#include <cassert>
#include <iostream>
#include <istream>
#include <limits>
#include <cmath>


#include "utilities.h"
#include "point.h"
#include "line.h"

#include "SimpleArray.h"

#include "element.hpp"

#include "mesh.hpp"

typedef Point Node; 

class Mesh {
public:
   bool checkElementAngles(Number angle_threshold) const;
   Number maxAngle(const Element& e) const;
   int numNodes() const;
   int numElements() const;
   friend std::istream& operator>>(std::istream&, Mesh&);
private:
   SimpleArray<Node>    node_table;
   SimpleArray<Element> elemetn_table;
};