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
    
    void Reverse();
    
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

template <typename Type>
void Swap(vector<Type> & v, int i, int j) {
    Type temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

template <typename Type>
void MyStack<Type>::Reverse() {
    if (!(this->IsEmpty())) {
        int front = 0;
        int back = (int) (elems.size()-1);
        while (front < back) {
            Swap(elems, front, back);
            front++;
            back--;
        }
    }
}

template <typename Type>
struct Node {
    Type value;
    Node * next;
};

template <typename Type>
void Sutter(Node<Type> * list) {
    while (list != NULL) {
        Node<Type> * temp;
        temp -> value = list -> value;
        temp -> next = list -> next;
        list -> next = temp;
        list = temp -> next;
    }
}

#endif /* utility_hpp */
