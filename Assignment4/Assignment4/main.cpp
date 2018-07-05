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
    return 0;
}
