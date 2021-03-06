//
//  utility.cpp
//  Assignment3
//
//  Created by Reza Asad on 7/3/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"
#include <numeric>

string ToLower(string s) {
    string result;
    for (int i = 0; i < s.size(); ++i) {
        result += tolower(s[i], locale());
    }
    return result; 
}

bool operator < (const entryT & lhs, const entryT & rhs) {
    if (ToLower(lhs.lastName) == ToLower(rhs.lastName)) return ToLower(lhs.firstName) < ToLower(rhs.firstName);
    else return ToLower(lhs.lastName) < ToLower(rhs.lastName);
}

bool operator == (const entryT & lhs, const entryT & rhs) {
    if (ToLower(lhs.lastName) == ToLower(rhs.lastName)) return ToLower(lhs.firstName) == ToLower(rhs.firstName);
    return false;
}

void addContact(vector<entryT> & newContacts, set<entryT> & contacts) {
    for (int i = 0; i < newContacts.size(); ++i) {
        contacts.insert(newContacts[i]);
    }
}

void LoadCityMap(vector<city> & cities, map<string, string> & cityMap) {
    for (int i = 0; i < cities.size(); ++i) {
        string coordinates = to_string(cities[i].coordinates.x) + '-' +to_string(cities[i].coordinates.y);
        cityMap[coordinates] = cities[i].name;
    }
}

string FindCity(pointT & pCoordinates, map<string, string> & cityMap) {
    string coordinates = to_string(pCoordinates.x) + '-' +to_string(pCoordinates.y);
    return cityMap[coordinates];
}

int Cannonball(int height) {
    if (height == 0) return 0;
    return height * height + Cannonball(height - 1);
}

void swap(unsigned long beg, unsigned long end, string & s) {
    char temp = s[beg];
    s[beg] = s[end];
    s[end] = temp;
}

void ReverseString(string & str, unsigned long beg, unsigned long end) {
    if (beg > end) return;
    swap(beg, end, str);
    ReverseString(str, beg+1, end-1);
}

bool IsMeasurable(int target, vector<int> & weights) {
    int sum = accumulate(weights.begin(), weights.end(), 0);
    if (sum == target) return true;
    if (sum < target) return false;
    for (int i = 0; i < weights.size(); ++i) {
        if (target == weights[i]) return true;
        vector<int> weightsExceptOne = weights;
        weightsExceptOne.erase(weightsExceptOne.begin()+i);
        if (IsMeasurable(target+weights[i], weightsExceptOne) or IsMeasurable(target, weightsExceptOne)) return true;
    }
    return false;
}




