//
//  utility.hpp
//  Assignmet6
//
//  Created by Reza Asad on 7/15/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

struct Movie {
    string name;
    int rating;
    string genre;
};

bool IsBadMovie(Movie & m);

template <typename Type>
void FilterQueue(queue<Type> & q, bool (IsBad)(Type &) ) {
    int count = 0;
    while (count < q.size()) {
        Type elem = q.front();
        q.pop();
        if (!IsBad(elem)) {
//            cout << elem << endl;
            q.push(elem);
            count++;
        }
    }
}

ostream & operator << (ostream & f, Movie & m);

#endif /* utility_hpp */
