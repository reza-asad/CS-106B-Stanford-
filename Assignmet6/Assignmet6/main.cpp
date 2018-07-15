//
//  main.cpp
//  Assignmet6
//
//  Created by Reza Asad on 7/15/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"

int main() {
    vector<Movie> vMovies = {{"Commander",9, "Action"}, {"Titanic", 8, "Drama"},
        {"Avatar", 6, "Drama"}, {"Knocked Up", 8, "Comedy"}, {"Home Alone", 6, "Drama"}};
    queue<Movie> qMovies;
    for (int i = 0; i < vMovies.size(); i++) {
        qMovies.push(vMovies[i]);
    }
    
    FilterQueue(qMovies, IsBadMovie);
    for (int i = 0; i < qMovies.size(); i++) {
        Movie m = qMovies.front();
        qMovies.pop();
        cout << m << endl;
    }
    return 0;
}
