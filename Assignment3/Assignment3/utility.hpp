//
//  utility.hpp
//  Assignment3
//
//  Created by Reza Asad on 7/3/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

// Question 1
string ToLower(string s);

struct entryT {
    string firstName;
    string lastName;
    string phoneNumber;
};

// This checks if two entryT are the same. Two entryT objects
// are the same if they have the first lastName and firstName.
//
// input:
//      const entryT & lhs: The left entryT.
//      const entryT & rhs: The right entryT.
// return:
//      boolean to see if the objects are equal.
bool operator == (const entryT & lhs, const entryT & rhs);

// This checks if one entryT is smaller than another. An entryT
// is smaller if it has smaller lastName. If the lastNames are
// the same an the one with smaller firstName is smaller.
//
// input:
//      const entryT & lhs: The left entryT.
//      const entryT & rhs: The right entryT.
// return:
//      boolean to see if lhs is smaller than rhs.
bool operator < (const entryT & lhs, const entryT & rhs);

// This adds new contact entryT objects to the set contacts.
//
// input:
//      vector<entryT> & newContacts: Vector containing the new
//      contacts.
//      set<entryT> & contacts: Set of existing contacts.
void addContact(vector<entryT> & newContacts, set<entryT> & contacts);


// Question 2
struct pointT {
    int x, y;
};

struct city {
    string name;
    pointT coordinates;
};

void LoadCityMap(vector<city> & cities, map<string, string> & cityMap);
string FindCity(pointT & pCoordinates, map<string, string> & cityMap);

#endif /* utility_hpp */
