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

vector<int> BestSubVec(vector<int> & v, int & left_beg, int & left_end,
                       int & right_beg, int & right_end) {
    vector<int> indices = {}
    int leftSum = sumVec(v, left_beg, left_end);
    int rightSum = sumVec(v, right_beg, right_end);
    int joinedSum = sumVec(v, left_beg, right_end);
    int max = leftSum;
    indices[0] = left_beg;
    indices[1] = left_end;
    if (rightSum > max) {
        max = rightSum;
        indices[0] = right_beg;
        indices[1] = right_end;
    }
    if (joinedSum > max) {
        max = joinedSum;
        indices[0] = left_beg;
        indices[1] = right_end;
    }
    return indices;
}

void SmartMaxSubVector(vector<int> & v, int & beg, int & end) {
    if (v.size() > 1) {
        int mid = (int) (v.size() / 2);
        vector<int> left(v.begin(), v.begin() + mid);
        vector<int> right(v.begin() + mid, v.end());
        int left_beg = 0;
        int left_end = mid;
        int right_beg = mid;
        int right_end = (int) v.size();
        
        SmartMaxSubVector(left, left_beg, left_end);
        SmartMaxSubVector(right, right_beg, right_end);
        vector<int> result = BestSubVec(v, left_beg, left_end, right_beg, right_end);
        beg = result[0];
        end = result[1];
    }
}
