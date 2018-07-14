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
    
    // Find the subvector with max sum
    vector<int> v3 = {-1,2,3,-4, 100, -200, 1000};
    vector<int> maxSubVec = NaiveMaxSubVector(v3);
    PrintVec(maxSubVec);
    
    // Using divide and conquer to find the subvector with max sum
    vector<int> v4 = {100, 4, 5, 10, -3, 10, -100, 1000};
    int beg = 0;
    end = (int) (v4.size() - 1);
    SmartMaxSubVector(v4, beg, end);
    cout << "The start is: " << beg << " The end is: " << end << endl;

    // Using dynamic programming find the subvector with max sum
    SmartestMaxSubVector(v4, beg, end);
    cout << "The start is: " << beg << " The end is: " << end << endl;
    return 0;
}
