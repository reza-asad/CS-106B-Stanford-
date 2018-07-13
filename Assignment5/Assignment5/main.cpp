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
    MergeSort(v);
    PrintVec(v);
    
    // Use the quicksort algorithm to sort a vector.
    vector<int> v2 = {5,8,9,1,100,20, 19,1};
    int end = (int) (v2.size() - 1);
    QuickSort(v2, 0, end);
    PrintVec(v2);
    
    return 0;
}
