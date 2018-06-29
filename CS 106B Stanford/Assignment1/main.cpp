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
    
    
    
    return 0;
}
