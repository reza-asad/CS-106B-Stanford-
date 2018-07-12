//
//  main.cpp
//  Assignment4
//
//  Created by Reza Asad on 7/5/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"

int main() {
    // Converting a vector of ints to linked list.
    vector<int> cells = {1,2,3,9};
    Cell * list = ConvertToList(cells);
    PrintList(list);

    list = ConvertToList2(cells);
    cout << "Calling the recursive vector to list convertor: " << endl;
    PrintList(list);
    
    // Compute the sum of elements in a linked list.
    cout << "The sume of elements in the list is: " << SumList(list) << endl;
    
    // Append a second list to a first list
    vector<int> v1 = {11,8,4,4,6};
    vector<int> v2 = {1,5,8};
    Cell * first = ConvertToList(v1);
    Cell * second = ConvertToList(v2);
    Append(first, second);
    cout << "After appending second list to first we have: " << endl;
    PrintList(first);
    
    // Printing the list now backwards.
    cout << "Printing the list backwards" << endl;
    PrintListBackwards(first);
    
    return 0;
}
