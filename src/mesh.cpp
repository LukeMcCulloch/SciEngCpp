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

typedef Point Node;        //Node class that behaves like a point

//extern istream& operator>>(istream& is, const Element& i);

class Element {

public:
   int operator[](int i) const;
   int numNodes()        const;
   //friend istream& operator>>(istream&, Element&);
private:
   SimpleArray<int> node_numbers;
};

//
/////////////////////////////////////////////////////////
// implementation
int Element::operator[](int i) const {
   return node_numbers[i];
}

int Element::numNodes() const {
   return node_numbers.numElts();
}
