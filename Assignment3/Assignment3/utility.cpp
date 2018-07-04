//
//  utility.cpp
//  Assignment3
//
//  Created by Reza Asad on 7/3/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"


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


