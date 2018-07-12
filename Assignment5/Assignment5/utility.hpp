//
//  utility.hpp
//  Assignment5
//
//  Created by Reza Asad on 7/12/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
void PrintVec(vector<Type> & v) {
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
}

template <typename Type>
void MergeVecs(vector<Type> & v, vector<Type> & left, vector<Type> & right) {
//    PrintVec(left);
//    PrintVec(right);
    int left_idx = 0;
    int right_idx = 0;
    for (int current = 0; current < v.size(); ++current) {
        if ((left_idx < v.size()) and (left[left_idx] < right[right_idx])) {
            v[current] = left[left_idx];
            left_idx += 1;
        } else {
            v[current] = right[right_idx];
            right_idx += 1;
        }
    }
}

template <typename Type>
void MergeSort(vector<Type> & v) {
    if (v.size() > 1) {
        unsigned long mid = v.size() / 2;
        vector<Type> left(v.begin(), v.begin() + mid);
        vector<Type> right(v.begin() + mid, v.end());
        MergeSort(left);
        MergeSort(right);
        MergeVecs(v, left, right);
    }
}

#endif /* utility_hpp */
