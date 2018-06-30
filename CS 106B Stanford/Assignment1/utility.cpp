//
//  utility.cpp
//  CS 106B Stanford
//
//  Created by Reza Asad on 6/29/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

#include "utility.hpp"
// Censoring a string given anoter string
// input:
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

// Censoring a string given anoter string in place
// input:
//      string text: A string to be censored
//      string remove: A string containing characters that we need
//                     to remove from text.
void CensorString2(string & text, string remove) {
    for (int i=0; i<text.length(); ++i) {
        if (remove.find(text[i]) != string::npos) {
            text.erase(i, 1);
            i--;
        }
    }
}

// Testing string censorship
// input:
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
GradeStats * ComputeGradesStats(string fileName) {
    // Open the file
    ifstream ifile;
    GradeStats * stats = new GradeStats;
    ifile.open(fileName);
    int count = 0;
    if (ifile.is_open()) {
        string sgrade;
        double minVal = 0;
        double maxVal = 0;
        double sumVal = 0;
        int igrade = 0;

        // Compute the min, max and avg during one pass of the file.
        while (getline(ifile, sgrade)) {
            igrade = stoi(sgrade);
            // First check the sanity of the grades
            if (igrade > 100 or igrade < 0) {
                cerr << "The file contains invalid grades" << endl;
            }
            if (igrade < minVal) {
                minVal = igrade;
            } else if (igrade > maxVal) {
                maxVal = igrade;
            }
            sumVal += igrade;
            count += 1;
        }
        double avgVal = sumVal/count;
        
        // Populate the struct
        stats->minScore = minVal;
        stats->maxScore = maxVal;
        stats->avgScore = avgVal;

    } else {
        ifile.clear();
        cerr << "Could not open the file: " << fileName << endl;
    }
    // Notify the clinet if the file was empty
    if (count==0)
        cout << "The file was empty" <<endl;
    return stats;
}
