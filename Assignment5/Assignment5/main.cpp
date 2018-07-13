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
    vector<int> v2 = {7,2,1,5,8,9};
//    QuickSort(v, 0, v.size()-1);
//    PrintVec(v);
    PivotSort(v2, 3);
    PrintVec(v2);
    return 0;
}
