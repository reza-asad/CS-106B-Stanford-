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
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <sstream>

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

// Question 5
int TreeHeight(nodeT * t);

bool IsBalanced(nodeT * t);

// Placing one queen in every row and column of chess board
// in such a way that they all survive.
void CreateBoard(vector<vector<bool>> & board, int dim);
void PrintChessBoard(vector<vector<bool>> & board);
bool CanAddQueen(vector<vector<bool>> & board, int row, int column);
void AddQueen(vector<vector<bool>> & board, int row, int column);
void RemoveQueen(vector<vector<bool>> & board, int row, int column);
bool PlaceQueens(vector<vector<bool>> & board, int row = 0);

#endif /* utility_hpp */
