//
//  utility.hpp
//  Assignmet6
//
//  Created by Reza Asad on 7/15/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <queue>
#include <fstream>
#include <map>

using namespace std;

struct Movie {
    string name;
    int rating;
    string genre;
};

bool IsBadMovie(Movie & m);

template <typename Type>
void FilterQueue(queue<Type> & q, bool (IsBad)(Type &) ) {
    int count = 0;
    while (count < q.size()) {
        Type elem = q.front();
        q.pop();
        if (!IsBad(elem)) {
            q.push(elem);
            count++;
        }
    }
}

ostream & operator << (ostream & f, Movie & m);

template <typename Type>
void swap(vector<Type> & v, int i, int j) {
    if (i != j) {
        Type temp = v[j];
        v[j] = v[i];
        v[i] = temp;
    }
}

template <typename Type>
int DefaultComp(Type a, Type b) {
    if (a == b) return 0;
    if (a < b) return -1;
    else return 1;
}

template <typename Type>
void SelectionSort(vector<Type> & v, int (comp)(Type, Type) = DefaultComp) {
    for (int i = 0; i < v.size(); ++i) {
        int minIdx = i;
        int minVal = v[i];
        for (int j = i + 1; j < v.size(); ++j) {
            if (comp(v[j], minVal) < 0) {
                minIdx = j;
                minVal = v[j];
            }
        }
        swap(v, i, minIdx);
    }
}

template <typename Type>
vector<Type> Removeuplicates(vector<Type> & v, int (comp)(Type, Type) = DefaultComp) {
    vector<Type> deduped;
    if (v.size() == 0) return deduped;
    // Sort the vector first
    SelectionSort(v);
    deduped.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
        if (comp(v[i], v[i-1]) != 0) {
            deduped.push_back(v[i]);
        }
    }
    return deduped;
}

#endif /* utility_hpp */
