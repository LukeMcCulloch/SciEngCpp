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

   the issue:  this function exploits knowledge of the 
   mesh representation directly.  This is a weakness 
   because, conceptually, this function is 
   independent of representation of the mesh.
   But here, if the mesh rep changes, then this function 
   has to change.  Let's fix that.
   */
   bool anglesOK = true;
   int ne = numElements();
   for (int eltNum = 0; eltNum < ne; eltNum++) {
      const Element& e = element_table[eltNum];      // e is an alias for eleement # eltNum
      if (maxAngle(e) > angle_threshold) {
         std::cout << "Element [";
         int nn = e.numNodes();
         for (int i = 0; i < nn; i++) {
            std::cout << node_table[e[i]]
            << "";
         }
         std::cout << "] has a large angle." << std::endl;
         anglesOK = false;
      }
   }

   return anglesOK;
}

// std::istream& operator>>(std::istream& instream, Mesh& m) {
//    int nNodes;
//    int nElements;
//    instream >> nNodes >> nElements;
//    m.node_table.setSize(nNodes);
//    m.element_table.setSize(nElements);
//    for (int nodeNum = 0; nodeNum < nNodes; nodeNum++) {
//       instream >> m.node_table[nodeNum]; // read in one node (point)
//    }
//    for (int elementNum = 0; elementNum < nElements; elementNum++) {
//       instream >>m.element_table[elementNum];  // read in one element
//    }
//    return instream;
// }



// page 215
NodeReader::NodeReader(Mesh& m, std::istream& instream) :
   mesh(m), in(instream) {}

int NodeReader::getSize() {
   int size;
   in >> size;
   return size;
}

Node* NodeReader::getNode() {
   int nodeNum;
   in >> nodeNum;
   return &mesh.node_table[nodeNum];
}

void operator >> (NodeReader& reader, Element& e) {
   int nNodesInElement = reader.getSize();
   e.node_ptrs.setSize(nNodesInElement);
   for (int i = 0; i < nNodesInElement; i++) {
      e.node_ptrs[i] = reader.getNode();
   }
}











std::istream& operator>>(std::istream& instream, Mesh& m) {
   // Set sizes of node and element tables
   int nNodes;
   int nElements;
   instream >> nNodes >> nElements;
   m.node_table.setSize(nNodes);
   m.element_table.setSize(nElements);

   // Read nodes
   for (int nodeNum = 0; nodeNum < nNodes; nodeNum++) {
      instream >> m.node_table[nodeNum]; // read in one node (point)
   }

   // Read elements
   NodeReader reader(m, instream);
   for (int elementNum = 0; elementNum < nElements; elementNum++) {
      reader >> m.element_table[elementNum];  // read in one element
   }
   return instream;
}