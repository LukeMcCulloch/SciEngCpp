
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
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // accumulte sums Sx and Sy in double(?) precision
    double sx = 0.0;
    double sy = 0.0;
    for (int i =0; i < n; i++) {
        sx += x[i];
        sy += y[i];
    }

    //compute coefficients
    double sx_over_n = sx/n;
    double stt = 0.0;
    double b = 0.0;
    for (int i = 0; i < n; i++) {
        double ti = x[i] -sx_over_n;
        stt += ti * ti;
        b += ti * y[i];
    }
    b /= stt;
    double a = (sy - sx*b)/n;

    // no destructor calls needed, 
    // because no "new" calls were needed.
    // delete [] x;
    // delete [] y;

    cout << a << "" << b << endl;
}