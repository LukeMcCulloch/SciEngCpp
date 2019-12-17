#pragma once


#include "SimpleArray.h"
#include "point.h"
#include "element.hpp"

typedef Point Node; 


class ElementsOfMesh;

class NodesOfMesh;

class Mesh {
public:
   friend ElementsOfMesh;    // iterator over elements of a mesh
   friend NodesOfMesh;       // Iterator over nodes of a mesh
   bool checkElementAngles(Number angle_threshold) const;
   Number maxAngle(const Element& e) const;

   int numNodes() const;     // no longer needed?
   int numElements() const;  // no longer needed?

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



class NodesOfMesh {
public:
    NodesOfMesh(const Mesh& m) :
        node_table(m.node_table), cur(m.node_table.numElts()-1) {}
    bool more() const { return cur >= 0; } // do more elements remain to be iterated?
    void advance()    { --cur; }
    const Node& current() const { return node_table[cur]; }
private:
   const SimpleArray<Node> node_table;
    int cur;
};


//class NodeReader