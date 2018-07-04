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
    
    // Locate a city based on it's coordinates.
    map<string, string> cityMap;
    city sf = {"SF", {1,0}};
    city nyc = {"NYC", {1,1}};
    city sj = {"SJ", {0,1}};
    city bos = {"BOS", {0,0}};
    vector<city> cities = {sf, nyc, sj, bos};
    // Load the map first
    LoadCityMap(cities, cityMap);
    // Retrieve city based on coordinate now
    for (int i = 0; i < cities.size(); ++i) {
        cout << FindCity(cities[i].coordinates, cityMap) << endl;
    }

    // Find number of cannonballs
    vector<int> heights = {0, 1, 2, 3};
    for (int i = 0; i < heights.size(); ++i) {
        cout << "with height " << heights[i] << "There are " << Cannonball(heights[i]) << " Cannonballs" << endl;
    }
    
    return 0;
}
