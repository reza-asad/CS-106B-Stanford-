//
//  main.cpp
//  Assignment7
//
//  Created by Reza Asad on 7/17/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include <iostream>
#include "utility.hpp"

int main() {
    MyStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
    return 0;
}
