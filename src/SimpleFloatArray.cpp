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
    while (p > ptr_to_data)*--p = *--q;
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