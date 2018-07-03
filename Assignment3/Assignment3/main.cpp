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
    if (myFriend < me) cout << myFriend.firstName << ", " << me.firstName << endl;
    
    // Check if the comparison is case sensative
    entryT Reza = {"reza", "Asad", "333-333-333"};
    if (me == Reza) cout << me.firstName << "=" << Reza.firstName << endl;
    
    return 0;
}
