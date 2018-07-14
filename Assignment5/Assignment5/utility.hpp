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
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename Type>
void PrintVec(vector<Type> & v) {
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << ", ";
    }
    cout << endl;
}

template <typename Type>
void MergeVecs(vector<Type> & v, vector<Type> & left, vector<Type> & right) {
    int left_idx = 0;
    int right_idx = 0;
    for (int current = 0; current < v.size(); ++current) {
        if ((left_idx < left.size()) and (right_idx < right.size())) {
            if (left[left_idx] < right[right_idx]) {
                v[current] = left[left_idx];
                left_idx += 1;
            } else {
                v[current] = right[right_idx];
                right_idx += 1;
            }
        } else if (left_idx < left.size()) {
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
template <typename Type>
void swap(vector<Type> & v, unsigned long i, unsigned long j) {
    Type temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

template <typename Type>
int PivotSort(vector<Type> & v, int beg, int end) {
    srand((int)time(NULL));
    int pivot = (rand() % (end+1-beg)) + beg;
    
    // Bring the pivot to the beginning
    swap(v, beg, pivot);
    pivot = beg;
    
    // Swap with respect to the pivot untill begin index exceeds the end.
    while (beg < end) {
        if (beg == pivot) {
            if (v[end] < v[pivot]) {
                swap(v, end, pivot);
                pivot = end;
                beg++;
            } else {
                end--;
            }
        } else if (end == pivot) {
            if (v[beg] > v[pivot]) {
                swap(v, beg, pivot);
                pivot = beg;
                end--;
            } else {
                beg++;
            }
        }
    }
    return pivot;
}

template <typename Type>
void QuickSort(vector<Type> & v, int beg, int end) {
    if (beg < end) {
        int pivot = PivotSort(v, beg, end);
        QuickSort(v, beg, pivot-1);
        QuickSort(v, pivot+1, end);
    }
}

// This finds the subvector with maximum sum.
//
// input:
//      vector<int> v: the input vector.
// return:
//      The subvector with maximum sum.
vector<int> NaiveMaxSubVector(vector<int> & v);

// This finds the beginning and end index to the subvector
// with maximum sum.
//
// input:
//      vector<int> & v: The input vector.
//      int & beg: The beginning index of the vector.
//      int & end: The end index of the vector.
void SmartMaxSubVector(vector<int> & v, int & beg, int & end);

void SmartestMaxSubVector(vector<int> & v, int & beg, int & end);

#endif /* utility_hpp */
