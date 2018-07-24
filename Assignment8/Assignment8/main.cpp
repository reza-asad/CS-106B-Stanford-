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
    vector<string> v1 = {"h", "e", "q", "a", "f", "p", "q"};
    vector<string> v2 = {"b", "d", "a", "g", "h", "c","a"};
    nodeT * t1 = BuildBST(v1);
    nodeT * t2 = BuildBST(v2);
    cout << "The two trees are equal: " << IsTreeEqual(t1, t2) << endl;
    
    // Trim leaves of a tree
    TrimLeaves(t1);
    InOrderPrint(t1);
    
    // Check if a tree is balanced
    bool b = IsBalanced(t2);
    cout << "Is the tree balanced: " << b << endl;
    InOrderPrint(t2);
    
    // Create a chess board;
    const int dim = 8;
    vector<vector<bool>> board;
    CreateBoard(board, dim);
    
    return 0;
}
