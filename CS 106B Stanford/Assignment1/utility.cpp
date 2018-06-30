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

// Censoring a string given anoter string
// Input:
//      string text: A string to be censored
//      string remove: A string containing characters that we need
//                     to remove from text.
// return:
//      string result: The censored string.
string CensorString1(string text, string remove) {
    string result = "";
    for (int i=0; i<text.length(); ++i) {
        if (remove.find(text[i]) == string::npos) {
            result += text[i];
        }
    }
    return result;
}

void CensorString2(string & text, string remove) {
    for (int i=0; i<text.length(); ++i) {
        if (remove.find(text[i]) != string::npos) {
            text.erase(i, 1);
            i--;
        }
    }
}

// Testing string censorship
// Input:
//      vector myAnswers: A vector containing the answers I get from my functions.
//      vector trueAnswers: A vectore containing the true answers to my examples.
// return:
//      A boolean indicating if all tests have passed.
bool TestCensorString(vector<string> myAnswers, vector<string> trueAnswers) {
    if (myAnswers.size() != trueAnswers.size()) {
        cout << "Vectors for My Solution and the True Solution Must be of Same Size" << endl;
        return false;
    } else {
        for (int i=0; i<myAnswers.size(); ++i) {
            if (myAnswers[i] != trueAnswers[i]) {
                cout << myAnswers[i] << " not equal to " << trueAnswers[i] << endl;
                return false;
            }
        }
        cout << "All the test have passed!" << endl;
        return true;
    }
}
