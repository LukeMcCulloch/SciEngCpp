#include "SimpleArray.h"

template<class T>
SimpleArray<T>::SimpleArray(int n) {

   num_elts = n;
   ptr_to_data = new T[n];

}

template<class T>
SimpleArray<T>::SimpleArray() {

   num_elts = 0;
   ptr_to_data = 0;

}

template<class T>
SimpleArray<T>::SimpleArray(const SimpleArray<T>& a) {

   num_elts = a.num_elts;
   ptr_to_data = new T[num_elts];
   copy(a);  // Copy a's elements
}

template<class T>
void SimpleArray<T>::copy(const SimpleArray<T>& a) {
   //Copy a's elements to the elements of *this
   T* p = ptr_to_data + num_elts;
   T* q = a.ptr_to_data + num_elts;
   while (p > ptr_to_data) *--p = *--q; 
   /*
   * prefix has precedence over pointer
   *--p = *--q  <=> *(--p) = *(--q)
   so we decrement both pointers and then dereference
   to set each member of the array in thorough fashion
   */
}

template<class T>
SimpleArray<T>::~SimpleArray() {
   delete [] ptr_to_data;
}

template<class T>
T& SimpleArray<T>::operator[](int i) {
   return ptr_to_data[i];
}

template<class T>
int SimpleArray<T>::numElts() {
   return num_elts;
}


template<class T>
void SimpleArray<T>::setSize(int n) {
   if (n != num_elts) {
      delete [] ptr_to_data;      // Delete old elements
      num_elts = n;               // set new count
      ptr_to_data = new T[n]; // set and allocate new elements
   }
}

// array to array assignment:
template<class T>
SimpleArray<T>& SimpleArray<T>::operator=(const SimpleArray<T>& rhs) {
   if (ptr_to_data != rhs.ptr_to_data) { // do not copy thyself
      setSize( rhs.num_elts );
      copy(rhs);
   }
   return *this;
}

// scalar assignment:
template<class T>
SimpleArray<T>& SimpleArray<T>::operator=(T rhs) {
   T* p = ptr_to_data + num_elts;
   while (p > ptr_to_data) *--p = rhs; 
   return *this;
}