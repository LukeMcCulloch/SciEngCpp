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


int Mesh::numElements() const {
   return element_table.numElts();
}

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
   /* 
   * angle_threshold is the max angle allowable
   * maxAngle is the max angle computed
   */
   bool anglesOK = true;
   int ne = numElements();
   for (int eltNum = 0; eltNum < ne; eltNum++) {
      const Element& e = element_table[eltNum];      // e is an alias for eleement # eltNum
      if (maxAngle(e) > angle_threshold) {
         std::cout << "Element [";
         int nn = e.numNodes();
         for (int i = 0; i < nn; i++) {
            std::cout << e
            //node_table[e[i]]
            << "";
         }
         std::cout << "] has a large angle." << std::endl;
         anglesOK = false;
      }
   }

   return anglesOK;
}