#pragma once


#include "SimpleArray.h"
#include "point.h"
#include "element.hpp"

typedef Point Node; 


class ElementsOfMesh;


class Mesh {
public:
   friend ElementsOfMesh;    // iterator over elements of a mesh
   bool checkElementAngles(Number angle_threshold) const;
   Number maxAngle(const Element& e) const;
   int numNodes() const;
   int numElements() const;
   friend std::istream& operator>>(std::istream&, Mesh&);
private:
   SimpleArray<Node>    node_table;
   SimpleArray<Element> element_table;
};

class ElementsOfMesh {
public:
    ElementsOfMesh(const Mesh& m) :
        element_table(m.element_table), cur(m.element_table.numElts()-1) {}
    bool more() const { return cur >= 0; } // do more elements remain to be iterated?
    void advance()    { --cur; }
    const Element& current() const { return element_table[cur]; }
private:
   const SimpleArray<Element> element_table;
    int cur;
};