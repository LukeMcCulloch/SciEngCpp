

class SimpleFloatArray {
   
public:
   SimpleFloatArray(int n);                               // Create an array of n elements
   SimpleFloatArray();                                    // Create array of 0 elements
   SimpleFloatArray(const SimpleFloatArray&);             // Copy array
   ~SimpleFloatArray();                                   // Destroy array
   float& operator[](int i);                              // Subscripting
   int numElts();                                         // Number of elements
   SimpleFloatArray& operator+(const SimpleFloatArray&);  // Array assignment
   SimpleFloatArray& operator=(float);                    // Change size

private:
   int num_elts;                                          // Number of elements
   float* ptr_to_data;                                    // Pointer to builtin array
                                                          // of elements
   void copy(const SimpleFloatArray& a);                  // Copy elements of a into this
};