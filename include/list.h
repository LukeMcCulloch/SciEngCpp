#pragma once

//#include "point.h"

//typedef Point Node; 

//template<class T>
//class ListIterator;



template<class T>
class List;




template<class T>
class ListIterator {
public:
   ListIterator(const List<T>& list) : cur(list.first) {}
   bool more()    const { return cur != 0;  }
   T    current() const { return cur->datum;}
   void advance()       { cur = cur->link;  }
private:
   typename List<T>::Node* cur;
   //auto List<T>::Node* cur;
};


template<class T>
class List {
public:
   List() : first(0), last(0) {}

   void add(T x) {
      if (first == 0) first = last = new Node();
      else last = last -> link = new Node(x);
   }
   void remove(T x);
   // ...

   friend class ListIterator<T>;
private:
   class Node {
   public:
      Node(T x) : link(0), datum(x) {}
      Node* link;
      T datum;
   };

   Node* first;
   Node* last;
};

