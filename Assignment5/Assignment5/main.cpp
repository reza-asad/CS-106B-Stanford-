//
//  main.cpp
//  Assignment5
//
//  Created by Reza Asad on 7/12/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"

int main() {
    vector<int> v = {10 ,9, 100, 2, 24, 0, 9};
    MergeSort(v);
    PrintVec(v);
    return 0;
}
