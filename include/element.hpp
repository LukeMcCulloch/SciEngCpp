#pragma once


#include "SimpleArray.h"

typedef Point Node;        //Node class that behaves like a point

//extern istream& operator>>(istream& is, const Element& i);


class NodesOfElement;

class NodeReader;

class Mesh;


class Element {

public:
   int operator[](int i) const;
   int numNodes()        const;
   
   friend class NodesOfElement;            // iterator over nodes of an element


   //old istream
   //friend std::istream& operator >> (std::istream&, Element& );
   //friend std::ostream& operator << (std::ostream&, const Element& );


   friend void operator >> (NodeReader& reader, Element& e);
   friend std::ostream& operator << (std::ostream& os, const Element& e);



   Number maxAngle() const;


private:

   /* Since an Element should not know the mapping between node numbers and Node objects
   *  an Element is represented by an array of pointers to Node objects rather than 
   *  an array of node numbers.
   */ 

   SimpleArray<int> node_numbers; // TDB: remove
   SimpleArray<Node*> node_ptrs;
};



class NodesOfElement {
public:
   NodesOfElement(const Element& e) :
      node_ptrs(e.node_ptrs), cur(e.node_ptrs.numElts()-1) {}

//iteration
   bool more() const { return cur >= 0; } // do more nodes remain to be iterated?
   void advance()    { --cur; }
   Node& current() const { return *node_ptrs[cur]; }

//Neighbor of current iterate
   Node& ccwNeighbor() const { return *node_ptrs[ ( cur + 1)%node_ptrs.numElts() ]; }
   Node& cwNeighbor() const{
      int numNodes = node_ptrs.numElts();
      return *node_ptrs[ (cur + numNodes - 1)%numNodes];
   }

   friend class Element;

private:
   const SimpleArray<Node*>& node_ptrs;
   int cur;
};



