//
//  utility.cpp
//  Assignment3
//
//  Created by Reza Asad on 7/3/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"


bool operator < (const entryT & lhs, const entryT & rhs) {
    if (lhs.lastName == rhs.lastName) return lhs.firstName < rhs.firstName;
    else return lhs.lastName == rhs.lastName;
}

void addContact(vector<entryT> & newContacts, set<entryT> & contacts) {
    for (int i = 0; i < newContacts.size(); ++i) {
        contacts.insert(newContacts[i]);
    }
}

