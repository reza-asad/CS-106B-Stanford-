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
    vector<string> myAnswers;
    vector<string> trueAnswers;
    
    string myAnswer="";
    myAnswer = CensorString1("Stanford University", "nt");
    myAnswers.push_back(myAnswer);
    trueAnswers.push_back("Saford Uiversiy");
    
    myAnswer = CensorString1("Llamas like to laugh", "la");
    myAnswers.push_back(myAnswer);
    trueAnswers.push_back("Lms ike to ugh");

    myAnswer = CensorString1("Coding during exams", "");
    myAnswers.push_back(myAnswer);
    trueAnswers.push_back("Coding during exams");

    myAnswer = CensorString1("last test", "b");
    myAnswers.push_back(myAnswer);
    trueAnswers.push_back("last test");

    TestCensorString(myAnswers, trueAnswers);
    
    // Testing CensorString2
    string test_str = "Stanford University";
    CensorString2(test_str, "nt");
    myAnswers.push_back(test_str);
    trueAnswers.push_back("Saford Uiversiy");

    test_str = "Llamas like to laugh";
    CensorString2(test_str, "la");
    myAnswers.push_back(test_str);
    trueAnswers.push_back("Lms ike to ugh");

    test_str = "Coding during exams";
    CensorString2(test_str, "");
    myAnswers.push_back(test_str);
    trueAnswers.push_back("Coding during exams");

    test_str = "last test";
    CensorString2(test_str, "b");
    myAnswers.push_back(test_str);
    trueAnswers.push_back("last test");

    return 0;
}
