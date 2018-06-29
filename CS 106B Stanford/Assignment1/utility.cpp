//
//  utility.cpp
//  CS 106B Stanford
//
//  Created by Reza Asad on 6/29/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "iostream"
#include "utility.hpp"
#include "vector"

string CensorString1(string text, string remove) {
    string result = "";
    for (int i=0; i<text.length(); ++i) {
        for (int j=0; j<remove.length(); ++j) {
            if (text[i] != remove[j]) {
                result += text[i];
            }
        }
    }
    return result;
}

bool TestCensorString(vector<string> texts, vector<string> answers) {
    if (texts.size() != answers.size()) {
        cout << "The Texts and the Solution Must be of Same Size" << endl;
        return false;
    } else {
        for (int i=0; i<texts.size(); ++i) {
            if (texts[i] != answers[i]) {
                return false;
            }
        }
        return true;
    }
}
