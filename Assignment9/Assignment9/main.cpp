//
//  main.cpp
//  Assignment9
//
//  Created by Reza Asad on 7/27/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>

#include "utility.hpp"

int main() {
    set<int> mySet;
    mySet.insert(0);
    mySet.insert(1);
    mySet.insert(3);
    mySet.insert(-1);
    for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
