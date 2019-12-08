#include "SimpleFloatArray.h"

SimpleFloatArray::SimpleFloatArray(int n) {

   num_elts = n;
   ptr_to_data = new float[n];

}

// Boccherini

SimpleFloatArray::SimpleFloatArray() {

   num_elts = 0;
   ptr_to_data = 0;

}

SimpleFloatArray::SimpleFloatArray(const SimpleFloatArray& a) {

   num_elts = a.num_elts;
   ptr_to_data = new float[num_elts];
   copy(a);  // Copy a's elements
}

void SimpleFloatArray::copy(const SimpleFloatArray& a) {
   //Copy a's elements to the elements of *this
   float* p = ptr_to_data + num_elts;
   float* q = a.ptr_to_data + num_elts;
   while (p > ptr_to_data) *--p = *--q; 
   /*
   * prefix has precedence over pointer
   *--p = *--q  <=> *(--p) = *(--q)
   so we decrement both pointers and then dereference
   to set each member of the array in thorough fashion
   */
}

SimpleFloatArray::~SimpleFloatArray() {
   delete [] ptr_to_data;
}

float& SimpleFloatArray::operator[](int i) {
   return ptr_to_data[i];
}

int SimpleFloatArray::numElts() {
   return num_elts;
}


void SimpleFloatArray::setSize(int n) {
   if (n != num_elts) {
      delete [] ptr_to_data;      // Delete old elements
      num_elts = n;               // set new count
      ptr_to_data = new float[n]; // set and allocate new elements
   }
}

// array to array assignment:
SimpleFloatArray& SimpleFloatArray::operator=(const SimpleFloatArray& rhs) {
   if (ptr_to_data != rhs.ptr_to_data) { // do not copy thyself
      setSize( rhs.num_elts );
      copy(rhs);
   }
   return *this;
}

// scalar assignment:
SimpleFloatArray& SimpleFloatArray::operator=(float rhs) {
   float* p = ptr_to_data + num_elts;
   while (p > ptr_to_data) *--p = rhs; 
   return *this;
}