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
// Censoring a string given anoter string
// input:
//      string text: A string to be censored
//      string remove: A string containing characters that we need
//                     to remove from text.
// return:
//      string result: The censored string.
string CensorString1(string text, string remove);

// Censoring a string given anoter string in place
// input:
//      string text: A string to be censored
//      string remove: A string containing characters that we need
//                     to remove from text.
void CensorString2(string & text, string remove);

// Testing string censorship
// input:
//      vector myAnswers: A vector containing the answers I get from my functions.
//      vector trueAnswers: A vectore containing the true answers to my examples.
// return:
//      A boolean indicating if all tests have passed.
bool TestCensorString(vector<string> texts, vector<string> answers);

// Question 2
struct GradeStats {
    double minScore;
    double maxScore;
    double avgScore;
};

// This reads the grades in a file line by line.
// Checks the validity of the grades (0 <= grade <= 100).
// Computes the min, max and average grade during one
// pass of the file.
//
// Input:
//      string fileName: The name of the file containing the grades.
// return:
//      GradeStats* stats: A pointer to the structure that contains
//      the computed statistics.
GradeStats* ComputeGradesStats(string fileName);

// Question 3
// This will open a file and prints out the number of time
// each alphabet letter exists in the file (not case sensitive)
//
// input:
//      string fileName: The file name
//
void CountLetters(string fileName);

#endif /* utility_hpp */
