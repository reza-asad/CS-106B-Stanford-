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
    int newSum = 0;
    vector<int> bestSubVec = {};
    vector<int> newSubVec = {};
    for (int i = 0; i < v.size(); ++i) {
        newSum = v[i];
        newSubVec = {};
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
    if (newSum > maxSum) {
        maxSum = newSum;
        bestSubVec = newSubVec;
    }
    return bestSubVec;
}

int SumVec(vector<int> & v, int beg, int end) {
    int sum = 0;
    for (int i = beg; i <= end; ++i) {
        sum += v[i];
    }
    return sum;
}

vector<int> BestSubVec(vector<int> & v, int & left_beg, int & left_end,
                       int & right_beg, int & right_end) {
    vector<int> indices;
    int beg = left_beg;
    int end = right_end;
    int maxSum = v[left_beg];
    int leftSum = v[left_beg];
    int rightSum = v[right_end];
    int l = beg+1;
    int r = end-1;
    while ((l <= right_end) and (r >= left_beg)) {
        leftSum += v[l];
        rightSum += v[r];
        if (leftSum > maxSum) {
            maxSum = leftSum;
            beg = left_beg;
            end = l;
        } else if (rightSum > maxSum) {
            maxSum = rightSum;
            beg = r;
            end = right_end;
        }
        l++;
        r--;
    }
    indices.push_back(beg);
    indices.push_back(end);
    return indices;
}

void SmartMaxSubVector(vector<int> & v, int & beg, int & end) {
    if (beg < end) {
        int mid = beg + (end - beg) / 2;
        int left_beg = beg;
        int left_end = mid;
        int right_beg = mid + 1;
        int right_end = end;
        SmartMaxSubVector(v, left_beg, left_end);
        SmartMaxSubVector(v, right_beg, right_end);
        
        vector<int> indices = BestSubVec(v, left_beg, left_end, right_beg , right_end);
        beg = indices[0];
        end = indices[1];
    }
}

void SmartestMaxSubVector(vector<int> & v, int & beg, int & end) {
    int maxSum = 0;
    if (v.size() > 0) {
        int tempSum = v[0];
        maxSum = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > (tempSum + v[i])) {
                tempSum = v[i];
                if (maxSum < tempSum) {
                    maxSum = tempSum;
                    beg = i;
                    end = i;
                }
            } else if ((tempSum + v[i]) >= tempSum) {
                tempSum += v[i];
                if (maxSum < tempSum) {
                    maxSum = tempSum;
                    end = i;
                }
            } else {
                tempSum += v[i];
            }
        }
    }
    cout << "The maximum sum is: " << maxSum << endl;
}


