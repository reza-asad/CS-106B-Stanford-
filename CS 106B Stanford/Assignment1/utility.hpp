//
//  utility.hpp
//  CS 106B Stanford
//
//  Created by Reza Asad on 6/29/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

// Question 1
string CensorString1(string text, string remove);
void CensorString2(string & text, string remove);
bool TestCensorString(vector<string> texts, vector<string> answers);

// Question 2
struct GradeStats {
    double minScore;
    double maxScore;
    double avgScore;
};
GradeStats* ComputeGradesStats(string fileName);

// Question 3
void CountLetters(string fileName);

#endif /* utility_hpp */
