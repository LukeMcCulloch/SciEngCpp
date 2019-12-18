#pragma once


template<class T>
class SimpleArray {                                   // page 101
   
public:
   SimpleArray(int n);                                // Create an array of n elements
   SimpleArray();                                     // Create array of 0 elements
   SimpleArray(const SimpleArray<T>&);                // Copy array
   ~SimpleArray();                                    // Destroy array
   T& operator[](int i) const;                            // Subscripting
   int numElts() const;                                     // Number of elements
   SimpleArray<T>& operator=(const SimpleArray<T>&);  // Array assignment
   SimpleArray<T>& operator=(T);                  // scalar assignment
   void setSize(int n);                               // Change size 

private:
   int num_elts;                                      // Number of elements
   T* ptr_to_data;                                // Pointer to builtin array of elements
   void copy(const SimpleArray<T>& a);                // Copy elements of a into this
};

