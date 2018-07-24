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

int TreeHeight(nodeT * t) {
    if (t == NULL) return 0;
    return (1 + max(TreeHeight(t -> left), TreeHeight(t -> right)));
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

void CreateBoard(vector<vector<bool>> & board, int dim) {
    for (int row = 0; row < dim; ++row) {
        for (int column = 0; column < dim; column++) {
            board[row][column] = 0;
        }
    }
}

void AddQueen(vector<vector<bool>> & v, int row, int column) {
    v[row][column] = 1;
}

void RemoveQueen(vector<vector<bool>> & v, int row, int column) {
    v[row][column] = 0;
}

bool CanAddQueen(vector<vector<bool>> & v, int row, int column) {
    // check for vertical collision
    for (int i = 0; i < row; ++i) {
        if (v[i][column] == 1) return false;
    }
    // check for diagonal collision
    int j = 1;
    bool upLeft = ((row-j) > 0) and ((column-j) > 0);
    bool upRight = ((row-j) > 0) and ((column+j) > 0);
    while(upLeft or upRight ) {
        if (upLeft and (v[row-j][column-j] == 1)) return false;
        else if (upRight and (v[row-1][column+j] == 1)) return false;
        j++;
        upLeft = ((row-j) > 0) and ((column-j) > 0);
        upRight = ((row-j) > 0) and ((column+j) > 0);
    }
    return true;
}

bool PlaceQueens(vector<vector<bool>> & v, int row) {
    if (row == v.size()) return true;
    for (int column = 0; column < v[row].size(); ++column) {
        if (CanAddQueen(v, row, column)) AddQueen(v, row, column);
        if (PlaceQueens(v, row+1)) return true;
        else RemoveQueen(v, row, column);
    }
    return false;
}
