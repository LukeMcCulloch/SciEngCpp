#pragma once

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
   SimpleArray<Element> element_table;
};