//
//  main.cpp
//  Assignment5
//
//  Created by Reza Asad on 7/12/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "utility.hpp"

int main() {
    // Use the mergesort algorithm to sort a vector
    vector<int> v = {10 ,9, 100, 2, 24, 0, 9};
//    MergeSort(v);
//    PrintVec(v);
    
    // Use the quicksort algorithm to sort a vector.
//    srand((int)time(0));
//    cout << rand() % 10 << endl;
    QuickSort(v, 0, v.size()-1);
    PrintVec(v);
    return 0;
}
