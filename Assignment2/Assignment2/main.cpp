//
//  main.cpp
//  Assignment2
//
//  Created by Reza Asad on 7/1/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"
#include <regex>

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
    
    return 0;
}
