//
//  main.cpp
//  Assignment8
//
//  Created by Reza Asad on 7/19/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"

int main() {
    // Test if two trees are the same
    vector<string> v1 = {"b", "d", "a", "g"};
    vector<string> v2 = {"b", "d", "a", "c"};
    nodeT * t1 = BuildBST(v1);
    nodeT * t2 = BuildBST(v2);
    cout << "The two trees are equal: " << IsTreeEqual(t1, t2) << endl;
    
    return 0;
}
