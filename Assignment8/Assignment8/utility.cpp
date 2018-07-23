//
//  utility.cpp
//  Assignment8
//
//  Created by Reza Asad on 7/19/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

void InOrderPrint(nodeT * t) {
    if (t != NULL) {
        InOrderPrint(t -> left);
        cout << t -> key << endl;
        InOrderPrint(t -> right);
    }
}

void InsertInBST(nodeT * & t, string key) {
    if (t == NULL) {
        t = new nodeT;
        t -> key = key;
        t -> left = NULL;
        t -> right = NULL;
    }
    else if (key < (t -> key)) InsertInBST(t -> left, key);
    else InsertInBST(t -> right, key);
}

nodeT * BuildBST(vector<string> & v) {
    nodeT * t = new nodeT;
    t  = NULL;
    for (int i = 0; i < v.size(); ++i) {
        InsertInBST(t, v[i]);
    }
    return t;
}

bool IsTreeEqual(nodeT * t1, nodeT * t2) {
    if (t1 == NULL and t2 == NULL) return true;
    if (t1 == NULL or t2 == NULL) return false;
    return ((t1 -> key == t2 -> key) and
            IsTreeEqual(t1 -> left, t2 -> left) and
            IsTreeEqual(t1 -> right, t2 -> right));
}

void TrimLeaves(nodeT * & t) {
    if (t != NULL) {
        if (t -> left == NULL and t -> right == NULL) {
            delete t;
            t = NULL;
        } else {
            TrimLeaves(t -> left);
            TrimLeaves(t -> right);
        }
    }
}

bool IsBalanced(nodeT * t) {
    if (t != NULL) {
        int leftHeight = TreeHeight(t -> left);
        int rightHeight = TreeHeight(t -> right);
        if (abs(leftHeight - rightHeight) > 1) return false;
        return (IsBalanced(t -> left) and IsBalanced(t -> right));
    } else {
        return true;
    }
}

