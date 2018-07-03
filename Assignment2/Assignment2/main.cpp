//
//  main.cpp
//  Assignment2
//
//  Created by Reza Asad on 7/1/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"
#include <fstream>

int main() {
    // Create a vector of eamils first
    emailMsg email_one = {"Reza", "John", "blah blah", "spam"};
    emailMsg email_two = {"John", "Mary", "blah blah", "SPAM"};
    emailMsg email_three = {"Reza", "John", "blah blah", ""};
    emailMsg email_four = {"Reza", "John", "blah blah", "SPAM"};
    vector<emailMsg> emails = {email_one, email_two, email_three, email_four};
    // Remove the spam emails
    RemoveSpam(emails);
    // Check if they are truly removed
    for (int i=0; i<emails.size(); ++i) {
        if (emails[i].subject == "SPAM") {
            cerr << "The spam email was not removed" << endl;
            return 0;
        }
    }
    cout << "Success, no spam email!!" << endl;
    
    // Reverse a queue
    queue<int> q;
    q.push(1);
    q.push(3);
    q.push(10);
    ReverseQueue(q);
    // Print the elements of the queue now
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    // Check if html tags are correctly nested in a string
    string htmlStr = "<html><b><i>CS106 rules!</i></b></html>";
    bool isNested = IsCorrectlyNested(htmlStr);
    if (isNested) cout << "The html string is nested correctly."<<endl;
    else cout<< "The nesting was incorrect."<< endl;
    
    // Find the most frequent character in a file.
    char mostFrequent;
    int numOccurrences = 0;
    ifstream ifile("characters.txt");
    mostFrequent = MostFrequentCharacter(ifile, numOccurrences);
    cout << "The most frequent character is: " << mostFrequent <<
    " with frequency: " << numOccurrences << endl;
    
    // Count the number of treasures.
    const int numRows = 6;
    const int numCols = 6;
    bool treasureLocation[numRows][numCols] = {
        {true, false, false, false, false, true},
        {false, false, false, false, false, true},
        {true, true, false, true, false, true},
        {true, false, false, false, false, false},
        {false, false, true, false, false, false},
        {false, false, false, false, false, false}
    };

    bool ** ptrTreasureLocation;
    ptrTreasureLocation = new bool *[numRows];
    for (int r = 0 ; r < numRows; ++r) {
        ptrTreasureLocation[r] = treasureLocation[r];
    }
    int ** gridCounts;
    gridCounts = MakeGridOfCounts(ptrTreasureLocation, numRows, numCols);
    printGrid(gridCounts, numRows, numCols);
    
    delete ptrTreasureLocation;
    delete gridCounts;

    vector<vector<bool>> treasureLocation2;
    for (int r = 0; r < numRows; ++r) {
        vector<bool> temp;
        for (int c = 0; c < numCols; ++c) {
            temp.push_back(treasureLocation[r][c]);
        }
        treasureLocation2.push_back(temp);
    }
    
    vector<vector<int>> gridCounts2;
    gridCounts2 = MakeGridOfCounts(treasureLocation2);
    printGrid(gridCounts2, numRows, numCols);
    
    return 0;
}
