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

void CountLetters(string fileName) {
    ifstream ifile;
    ifile.open(fileName);
    if (ifile.is_open()) {
        string line;
        vector<int> alphabetCount(26);
        while(getline(ifile, line)) {
            int pos = 0;
            for (int i=0; i<line.length(); ++i) {
                if (isalpha(line[i])) {
                    pos = tolower(line[i], locale()) - 'a';
                    alphabetCount[pos] += 1;
                }
            }
        }
        // Print the number of times each alphabet letter appears
        string alphabets = "abcdefghijklmnopqrstuvwxyz";
        for (int i=0; i<alphabets.size(); ++i) {
            cout << alphabets[i] << ": " << alphabetCount[i] << endl;
        }
    } else {
        ifile.clear();
        cerr << "Could not open the file: " << fileName << endl;
    }
}
