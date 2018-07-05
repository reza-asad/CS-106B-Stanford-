//
//  utility.hpp
//  Assignment4
//
//  Created by Reza Asad on 7/5/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <vector>

using namespace std;

// Question 4
struct Cell {
    int value;
    Cell * next;
};

Cell * ConvertToList(vector<int> & cells);

#endif /* utility_hpp */
