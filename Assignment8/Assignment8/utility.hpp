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

void InOrderPrint(nodeT * t);

void InsertInBST(nodeT * & t, string key);

nodeT * BuildBST(vector<string> & v);

// Question 3.
// Check if two trees are equal.
bool IsTreeEqual(nodeT * t1, nodeT * t2);

// Question 4.
void TrimLeaves(nodeT * & t);

#endif /* utility_hpp */
