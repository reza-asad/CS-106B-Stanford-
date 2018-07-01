//
//  utility.cpp
//  Assignment2
//
//  Created by Reza Asad on 7/1/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Question 1
void RemoveSpam(vector<emailMsg> & emails) {
    int i = 0;
    while(0<=i and i < emails.size()) {
        if (emails[i].subject == "SPAM") {
            cout << "found SPAM!" << endl;
            emails.erase(emails.begin()+i);
            i--;
        }
        i++;
    }
}

// Question 2
void ReverseQueue(queue<int> & q) {
    stack<int> s;
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        s.push(e);
    }
    while (!s.empty()) {
        int e = s.top();
        s.pop();
        q.push(e);
    }
}
