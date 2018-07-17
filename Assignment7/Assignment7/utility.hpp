//
//  utility.hpp
//  Assignment7
//
//  Created by Reza Asad on 7/17/18.
//  Copyright © 2018 Reza Asad. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
class MyStack {
public:
    MyStack();
    ~MyStack();
    
    void push(Type e);
    Type pop();
    
    bool IsEmpty();
    
private:
    vector<Type> elems;
    
};

template <typename Type>
MyStack<Type>::MyStack() {
}

template <typename Type>
MyStack<Type>::~MyStack() {
}

template <typename Type>
void MyStack<Type>::push(Type e) {
    elems.push_back(e);
}

template <typename Type>
Type MyStack<Type>::pop() {
    Type top = elems[elems.size()-1];
    elems.pop_back();
    return top;
}

template <typename Type>
bool MyStack<Type>::IsEmpty() {
    return elems.size() == 0;
}

#endif /* utility_hpp */
