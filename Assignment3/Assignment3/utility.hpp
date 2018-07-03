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

using namespace std;

// Question 1
string ToLower(string s);

struct entryT {
    string firstName;
    string lastName;
    string phoneNumber;
};
bool operator == (const entryT & lhs, const entryT & rhs);
bool operator < (const entryT & lhs, const entryT & rhs);
void addContact(vector<entryT> & newContacts, set<entryT> & contacts);


#endif /* utility_hpp */
