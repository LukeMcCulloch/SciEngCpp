#include <cassert>
#include <iostream>
#include <limits>

#include <cmath>

#include "point.h"
#include "line.h"
#include "SimpleFloatArray.h"


using namespace std;
using std::cout;
using std::endl;



void linefit() {
    //Create arrays with the desired number of elements
    int n=0;
    cout << "give the size of the arrays n = " << n << endl;
    cin >> n;
    cout << "n = " << n << endl;
    SimpleFloatArray x(n);
    SimpleFloatArray y(n);

    //Read the data points
}

int main (){

    cout << "hello world!" << endl;
    linefit();
    
    return 0;

}