//
//  utility.cpp
//  Assignment5
//
//  Created by Reza Asad on 7/12/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

vector<int> NaiveMaxSubVector(vector<int> & v) {
    int maxSum = 0;
    vector<int> bestSubVec = {};
    for (int i = 0; i < v.size(); ++i) {
        int newSum = v[i];
        vector<int> newSubVec;
        newSubVec.push_back(v[i]);
        for (int j = i + 1; j < v.size(); ++j) {
            newSum += v[j];
            newSubVec.push_back(v[j]);
            if (newSum > maxSum) {
                maxSum = newSum;
                bestSubVec = newSubVec;
            }
        }
    }
    return bestSubVec;
}
