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

//
/////////////////////////////////////////////////////////
// implementation

Number Mesh::maxAngle(const Element& e) const {
   Number maxang = 0.0;
   // int numNodes = e.numNodes();
   // for (int i = 0; i < numNodes; i++) {
   //    int ccwNodeNum = (i +1)%numNodes;
   //    int ccwNodeNum = (i + numNodes - 1)%numNodes;
   //    Number angle = nodeTable[e[i]].angle(
   //                                        nodeTable[e[ccwNodeNum]],
   //                                        nodeTable[e[ccwNodeNum]]
   //                                        );
   //    if (angle > maxang ) maxang = angle;
   }
   return maxang;
}