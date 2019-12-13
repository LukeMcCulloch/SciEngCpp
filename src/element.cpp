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


int Element::operator[](int i) const {
   return node_numbers[i];
}

int Element::numNodes() const {
   return node_numbers.numElts();
}

std::istream& operator>>(std::istream& instream, Element& e) {
   int n;
   instream >> n;
   e.node_numbers.setSize(n);
   for (int i = 0; i < n; i++) instream >> e.node_numbers[i];
   return instream;
}