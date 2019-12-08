
#include <cassert>
#include <iostream>
#include <limits>
#include <cmath>


#include "utilities.h"
#include "point.h"
#include "line.h"
#include "SimpleArray.h"
#include "SimpleArray.cpp" //https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp

#include "linefit.hpp"

using namespace std;
using std::cout;
using std::endl;

void linefit() {
    //Create arrays with the desired number of elements
    int n=0;
    cout << "give the size of the arrays n = " << n << endl;
    cin >> n;
    cout << "n = " << n << endl;

    SimpleArray<Number> x(n);
    SimpleArray<Number> y(n);

    //Read the data points

}