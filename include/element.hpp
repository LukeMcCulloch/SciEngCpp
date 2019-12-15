#pragma once


#include "SimpleArray.h"

typedef Point Node;        //Node class that behaves like a point

//extern istream& operator>>(istream& is, const Element& i);

class Element {

public:
   int operator[](int i) const;
   int numNodes()        const;
   friend std::istream& operator>>(std::istream&, Element& );
   friend std::ostream&  operator<<(std::ostream&, const Element& );
private:
   SimpleArray<int> node_numbers;
};
