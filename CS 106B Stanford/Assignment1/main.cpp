//
//  main.cpp
//  CS 106B Stanford
//  This is Assignemnt1
//
//  Created by Reza Asad on 6/29/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//
//

#include <iostream>
#include "utility.hpp"

using namespace std;

int main() {
    // Testing CensorString1
    vector<string> sentences = {"Stanford University", "Llamas like to laugh",
        "Coding during exams", "last test"};
    vector<string> remvoes = {"nt", "la", "", "b"};
    vector<string> trueAnswers = {"Saford Uiversiy", "Lms ike to ugh",
        "Coding during exams", "last test"};
    vector<string> myAnswers;
    
    string myAnswer="";
    for (int i=0; i<sentences.size(); ++i) {
        myAnswer = CensorString1(sentences[i], remvoes[i]);
        myAnswers.push_back(myAnswer);
    }
    TestCensorString(myAnswers, trueAnswers);
    
    // Testing CensorString2
    // clear the previous answers
    myAnswers.clear();
    string test_str;
    for (int i=0; i<sentences.size(); ++i) {
        test_str = sentences[i];
        CensorString2(test_str, remvoes[i]);
        myAnswers.push_back(test_str);
    }
    TestCensorString(myAnswers, trueAnswers);
    
    return 0;
}
