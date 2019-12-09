#include <cassert>
#include <iostream>
#include <istream>
#include <limits>
#include <cmath>


#include "utilities.h"
#include "point.h"
#include "line.h"

#include "SimpleArray.h"
#include "SimpleArray.cpp" 

#include "element.hpp"

class Mesh {
public:
   bool checkElementAngles(Number angle_threshold) const;
};