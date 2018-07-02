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
#include <regex>

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

// Question 3
vector<string> ExtractTags(string htmlStr) {
    vector<string> tags;
    regex r("<[^<]*?>");
    smatch match;
    while (regex_search(htmlStr, match,r)) {
        tags.push_back(match[0]);
        htmlStr = match.suffix();
    }
    return tags;
}

bool TagsMatch(string closingTag, string openingTag) {
    if ((closingTag.length()-openingTag.length()) != 1) return false;
    for (int i = 2; i < closingTag.size(); ++i) {
        if (closingTag[i] != openingTag[i-1]) return false;
    }
    return true;
}

bool IsCorrectlyNested(string htmlStr) {
    vector<string> tags = ExtractTags(htmlStr);
    stack<string> sTags;
    for (int i = 0; i < tags.size(); ++i) {
        if (tags[i][1] != '/') {
            sTags.push(tags[i]);
        } else {
            string tag = sTags.top();
            if (!TagsMatch(tags[i], tag)) return false;
            sTags.pop();
        }
    }
    return sTags.size()==0;
}


