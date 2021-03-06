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

// This prints the contents of a linked list
//
// input:
//      Cell * list: The linked list to print.
void PrintList(Cell * list);

// This prints a list from the back using recursion.
void PrintListBackwards(Cell * list);

// This converts a vector of ints to a linked list.
//
// input:
//      vector<int> & cells: A vector of ints.
// return:
//      A linked list.
Cell * ConvertToList(vector<int> & cells);

// Exactly as above except the algorithm is recursive here.
Cell * ConvertToList2(vector<int> & cells);

// This sums the elemts of a linked list
//
// input:
//      Cell * list: A list containing int values.
// return:
//      Sum of the elements in the list.
int SumList(Cell *list);

// Question 6
// This Appends the second list to the first one.
//
// input:
//      Cell * first: first list.
//      Cell * second: second list.
void Append(Cell * & first, Cell * & second);


#endif /* utility_hpp */
