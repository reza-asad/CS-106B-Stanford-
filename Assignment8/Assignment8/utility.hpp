//
//  utility.hpp
//  Assignment8
//
//  Created by Reza Asad on 7/19/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <vector>

using namespace std;

struct nodeT {
    string key;
    nodeT * left;
    nodeT * right;
};

bool IsTreeEqual(nodeT * t1, nodeT * t2);

#endif /* utility_hpp */
