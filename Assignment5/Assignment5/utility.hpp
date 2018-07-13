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
unsigned long PivotSort(vector<Type> & v, unsigned long pivot) {
    unsigned long beg = 0;
    unsigned long end = v.size() - 1;
    while (beg < end) {
        if ((v[beg] > v[pivot]) and (v[end] < v[pivot])) {
            swap(v, beg, end);
            beg++;
            end--;
        } else if (v[beg] > v[pivot]) {
            if (end == pivot) {
                swap(v, beg, pivot);
                pivot = beg;
            }
            end--;
        } else if (v[end] < v[pivot]) {
            if (beg == pivot) {
                swap(v, pivot, end);
                pivot = end;
            }
            beg++;
        } else {
            beg++;
            end--;
        }
    }
    return pivot;
}

template <typename Type>
void QuickSort(vector<Type> & v, unsigned long beg, unsigned long end) {
    if (end > beg) {
        unsigned long pivot = (rand() % (end+1-beg)) + beg;
        pivot = PivotSort(v, pivot);
        QuickSort(v, beg, pivot-1);
        QuickSort(v, pivot+1, end);
    }
}

#endif /* utility_hpp */
