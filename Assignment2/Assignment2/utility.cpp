//
//  utility.cpp
//  Assignment2
//
//  Created by Reza Asad on 7/1/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <regex>
#include <map>

using namespace std;

// Question 1
void RemoveSpam(vector<emailMsg> & emails) {
    int i = 0;
    while(0<=i and i < emails.size()) {
        if (emails[i].subject == "SPAM") {
            cout << "found SPAM!" << endl;
            emails.erase(emails.begin()+i);
            i--;
        }
        i++;
    }
}

// Question 2
void ReverseQueue(queue<int> & q) {
    stack<int> s;
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        s.push(e);
    }
    while (!s.empty()) {
        int e = s.top();
        s.pop();
        q.push(e);
    }
}

// Question 3
vector<string> ExtractTags(string htmlStr) {
    vector<string> tags;
    regex r("<[^<]*?>");
    smatch match;
    while (regex_search(htmlStr, match,r)) {
        tags.push_back(match[0]);
        htmlStr = match.suffix();
    }
    return tags;
}

bool TagsMatch(string closingTag, string openingTag) {
    if ((closingTag.length()-openingTag.length()) != 1) return false;
    for (int i = 2; i < closingTag.size(); ++i) {
        if (closingTag[i] != openingTag[i-1]) return false;
    }
    return true;
}

bool IsCorrectlyNested(string htmlStr) {
    vector<string> tags = ExtractTags(htmlStr);
    stack<string> sTags;
    for (int i = 0; i < tags.size(); ++i) {
        if (tags[i][1] != '/') {
            sTags.push(tags[i]);
        } else {
            string tag = sTags.top();
            if (!TagsMatch(tags[i], tag)) return false;
            sTags.pop();
        }
    }
    return sTags.size()==0;
}

char MostFrequentCharacter(ifstream & ifile, int & numOccurrences) {
    char mostFrequent = ' ';
    if (ifile.is_open()) {
        string line;
        map<char, int> charFrequency;
        while (getline(ifile, line)) {
            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == ' ') continue;
                charFrequency[line[i]] += 1;
                if (charFrequency[line[i]] > numOccurrences) {
                    numOccurrences = charFrequency[line[i]];
                    mostFrequent = line[i];
                }
            }
        }
    } else {
        cerr << "The file is not open. Please open the file first" << endl;
    }
    return mostFrequent;
}

int ** MakeGridOfCounts(bool ** treasureLocation, int numRows, int numCols) {
    int ** treasureCounts;
    
    // Initialize the treasureCounts
    treasureCounts = new int *[numRows];
    for (int r = 0; r < numRows; ++r) {
        treasureCounts[r] = new int[numCols];
        for (int c = 0; c < numCols; ++c) {
            treasureCounts[r][c] = 0;
        }
    }

    // Count the treasures
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            int rowIdx[] = {r-1, r, r+1};
            int colIdx[] = {c-1, c, c+1};
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    if (rowIdx[i] > -1 and rowIdx[i] < numRows and colIdx[j] > -1 and colIdx[j] < numCols) {
                        treasureCounts[r][c] += treasureLocation[rowIdx[i]][colIdx[j]];
                    }
                }
            }
        }
    }
    return treasureCounts;
}

vector<vector<int>> MakeGridOfCounts(vector<vector<bool>> & treasureLocation) {
    unsigned long numRows = treasureLocation.size();
    unsigned long numCols = treasureLocation[0].size();
    vector<vector<int>> treasureCounts;
    
    // Initialize the treasureCounts
    for (int r = 0; r < numRows; ++r) {
        vector<int> temp;
        for (int c = 0; c < numCols; ++c) {
            temp.push_back(0);
        }
        treasureCounts.push_back(temp);
    }
    // Count the treasures
    for (int r = 0; r < numRows; ++r) {
        for (int c = 0; c < numCols; ++c) {
            int rowIdx[] = {r-1, r, r+1};
            int colIdx[] = {c-1, c, c+1};
            for (int i=0; i<3; ++i) {
                for (int j=0; j<3; ++j) {
                    if (rowIdx[i] > -1 and rowIdx[i] < numRows and colIdx[j] > -1 and colIdx[j] < numCols) {
                        treasureCounts[r][c] += treasureLocation[rowIdx[i]][colIdx[j]];
                    }
                }
            }
        }
    }
    return treasureCounts;
}
