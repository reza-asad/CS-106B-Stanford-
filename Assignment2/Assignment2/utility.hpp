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

// Question 3
// This checks if html tags such as <b>, <i> or <html> are matched
// against a corresponding </b>, </i>, </html>. This assumes the
// html string is correctly fromed.
//
// input:
//      string htmlStr: A correct string of html.
//
// return :
//      True if the every html opening tag is matched against
//      a corresponding closing tag.
bool IsCorrectlyNested(string htmlStr);

#endif /* utility_hpp */
