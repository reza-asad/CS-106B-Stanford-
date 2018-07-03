//
//  utility.hpp
//  Assignment2
//
//  Created by Reza Asad on 7/1/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

// Question 1
struct emailMsg {
    string to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};

// This read through the email objects and removes any email
// with subject SPAM.
//
// input:
//      vector<emailMsg> emails: A vector of emails object.
void RemoveSpam(vector<emailMsg> & emails);

// Question 2

// This reverses a queue of integers.
//
// input:
//      queue<int> & q: A queue which we reverse it's elements.
void ReverseQueue(queue<int> & q);

// Question 3
// This checks if html tags such as <b>, <i> or <html> are matched
// against a corresponding </b>, </i>, </html>. This assumes the
// html string is correctly fromed.
//
// input:
//      string htmlStr: A correct string of html.
//
// return :
//      True if the every html opening tag is matched against
//      a corresponding closing tag.
bool IsCorrectlyNested(string htmlStr);

// This iterates through a file and finds the character with most
// frequency except white space.
//
// input:
//      ifstream & if: Input file that the function is going to read.
//      int & numOccurrences: The number of times that the most frequent
//                            character appears. This must be initialized
//                            zero.
// return:
//      The most frequent character.
char MostFrequentCharacter(ifstream & ifile, int & numOccurrences);

// This prints the contents of a Grid object.
//
// input:
//      Grid g: A Grid object. For instnace, a vector of vector
//      or an array of array.
//      int numRows: Number of rows in the grid.
//      int numCols: Number of columns in the grid.
//
template<class Grid>
void printGrid(Grid g, int numRows, int numCols) {
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            cout << g[r][c] << ',';
            if (c == (numCols-1)) cout << endl;
        }
    }
    cout<<endl;
}

// This takes a grid of boolean indicating treasure locations. The
// function computes the number of treasures in a neighbourhood. The
// neighbourhood is defined as the cell itself and it's eight adjacent
// neibours. Note that this assumes the input is rectangular.
//
// input:
//      bool ** treasureLocation: A 2d array of booleans
//      that indicates the existence of treasure at each cell.
//      int nuRows: The number of rows.
//      int numCols: The number of columns.
// return:
//      A 2d array that has the count of treasures
//      at a location and it's eight adjacent neighbours.
int ** MakeGridOfCounts(bool ** treasureLocation, int numRows, int numCols);

// The same function as above except the input and output are different.
//
// input:
//      vector<vector<bool>> & treasureLocation: A rectangle of booleans
//      that indicates the existence of treasure at each cell.
// return:
//      A pointer to a vector<vector<int>> that has the count of treasures
//      at a location and it's eight adjacent neighbours.
vector<vector<int>> * MakeGridOfCounts(vector<vector<bool>> & treasureLocation);

#endif /* utility_hpp */
