//
//  utility.cpp
//  Assignment8
//
//  Created by Reza Asad on 7/19/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

void InsertInBST(nodeT * & t, string key) {
    if (t == NULL) {
        t = new nodeT;
        t -> key = key;
        t -> left = NULL;
        t -> right = NULL;
    }
    else if (key < t -> key) InsertInBST(t -> left, key);
    else InsertInBST(t -> right, key);
}

nodeT * BuildBST(vector<string> & v) {
    nodeT * t = new nodeT;
    for (int i = 0; i < v.size(); ++i) {
        InsertInBST(t, v[i]);
    }
    return t;
}

bool IsTreeEqual(nodeT * t1, nodeT * t2) {
    if (t1 == NULL and t2 == NULL) return true;
    if (t1 -> key != t2 -> key) return false;
    return (IsTreeEqual(t1 -> left, t2 -> left) and IsTreeEqual(t1 -> right, t2 -> right));
}
