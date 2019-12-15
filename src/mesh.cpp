#include <cassert>
#include <iostream>
#include <istream>
#include <limits>
#include <cmath>


#include "utilities.h"
#include "point.h"
#include "line.h"

#include "SimpleArray.h"
#include "SimpleArray.cpp" 

#include "element.hpp"
//#include "element.cpp"

#include "mesh.hpp"



Number Mesh::maxAngle(const Element& e) const {
   Number maxang = 0.0;
   int numNodes = e.numNodes();
   for (int i = 0; i < numNodes; i++) {
      int ccwNodeNum = (i +1)%numNodes;
      int cwNodeNum = (i + numNodes - 1)%numNodes;
      Number angle = node_table[e[i]].angle(
                                          node_table[e[cwNodeNum]],
                                          node_table[e[ccwNodeNum]]
                                          );
      if (angle > maxang ) maxang = angle;
   }
   return maxang;
}

bool Mesh:: checkElementAngles(Number angle_threshold) const {
   bool anglesOK = true;

   return anglesOK;
}