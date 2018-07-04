//
//  utility.hpp
//  Assignment3
//
//  Created by Reza Asad on 7/3/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

// Question 1
string ToLower(string s);

struct entryT {
    string firstName;
    string lastName;
    string phoneNumber;
};

// This checks if two entryT are the same. Two entryT objects
// are the same if they have the first lastName and firstName.
//
// input:
//      const entryT & lhs: The left entryT.
//      const entryT & rhs: The right entryT.
// return:
//      boolean to see if the objects are equal.
bool operator == (const entryT & lhs, const entryT & rhs);

// This checks if one entryT is smaller than another. An entryT
// is smaller if it has smaller lastName. If the lastNames are
// the same an the one with smaller firstName is smaller.
//
// input:
//      const entryT & lhs: The left entryT.
//      const entryT & rhs: The right entryT.
// return:
//      boolean to see if lhs is smaller than rhs.
bool operator < (const entryT & lhs, const entryT & rhs);

// This adds new contact entryT objects to the set contacts.
//
// input:
//      vector<entryT> & newContacts: Vector containing the new
//      contacts.
//      set<entryT> & contacts: Set of existing contacts.
void addContact(vector<entryT> & newContacts, set<entryT> & contacts);


// Question 2
struct pointT {
    int x, y;
};

struct city {
    string name;
    pointT coordinates;
};

// This loads the cityMap with coordinates and cities.
//
// input:
//      vector<city> & cities: cities
//      map<string, string> & cityMap: A map that find a city based on
//      it's coordinates. The coordinate format is 'x-y'.
void LoadCityMap(vector<city> & cities, map<string, string> & cityMap);

// This lets the client to find a city based on it coordinate pointT.
//
// input:
//      pointT & pCoordinates: The coordinate of the city.
//      map<string, string> & cityMap: A map of coordinates (in string)
//      to city. The coordinate format is 'x-y'
// return:
//      The name of the city with the input coordinates.
string FindCity(pointT & pCoordinates, map<string, string> & cityMap);

// Question 3
// This is easy and similar to Question1

// Question 4
// This return the number of cannonballs in a pyramid
//
// input:
//      int height: The height of the pyramid
// return:
//      The number of cannonballs.
int Cannonball(int height);

// Qeustion 5
// This reverses a string in place.
//
// input:
//      string & str: The string that is going to be reversed.
//      unsigned long beg: The beg index position for the string.
//      unsigned long end: The end index position for the string.
void ReverseString(string & str, unsigned long beg, unsigned long end);

// Question 6
// Super easy

// Question 7
// This tell us if a target is measurable given a number of weights.
//
// input:
//      int target: The target weight.
//      vector<int> & weights: A vector containing the measuring weights.
// return:
//      Is the target measurable.
bool IsMeasurable(int target, vector<int> & weights);


#endif /* utility_hpp */
