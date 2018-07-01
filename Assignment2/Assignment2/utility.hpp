//
//  utility.hpp
//  Assignment2
//
//  Created by Reza Asad on 7/1/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Question 1
struct emailMsg {
    string to;
    string from;
    string message;
    string subject;
    int date;
    int time;
};

// This read through the email objects and removes any email
// with subject SPAM.
//
// input:
//      vector<emailMsg> emails: A vector of emails object.
void RemoveSpam(vector<emailMsg> & emails);

// Question 2

// This reverses a queue of integers.
//
// input:
//      queue<int> & q: A queue which we reverse it's elements.
void ReverseQueue(queue<int> & q);

#endif /* utility_hpp */
