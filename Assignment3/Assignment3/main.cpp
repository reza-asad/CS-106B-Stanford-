//
//  main.cpp
//  Assignment3
//
//  Created by Reza Asad on 7/3/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"

int main() {
    // Create a set of entryT
    set<entryT> myContacts;
    entryT me = {"Reza", "Asad", "444-444-4444"};
    entryT myFriend = {"Mehrdad", "Asad", "666-666-666"};
    vector<entryT> newContacts = {me, myFriend};
    addContact(newContacts, myContacts);
    // Check if the comparison is correct
    if (myFriend < me) cout << myFriend.firstName << " " << me.firstName << endl;
    
    return 0;
}
