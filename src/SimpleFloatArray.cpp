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



//    return ptr_to_data[i];