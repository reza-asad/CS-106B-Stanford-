//
//  utility.cpp
//  Assignment7
//
//  Created by Reza Asad on 7/17/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#include "utility.hpp"

template <typename Type>
MyStack<Type> :: MyStack() {
}

template <typename Type>
MyStack<Type> :: ~MyStack() {
}

template <typename Type>
void MyStack<Type> :: push(Type e) {
    elems.push_back(e);
}
