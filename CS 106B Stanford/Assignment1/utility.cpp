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
        if (remove.find(text[i]) == string::npos) {
            result += text[i];
        }
    }
    return result;
}

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
