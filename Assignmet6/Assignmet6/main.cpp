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
    queue<int> q;
    q.push(1);
    q.push(2);
    int a = q.front();
    cout << a << endl;
    return 0;
}
