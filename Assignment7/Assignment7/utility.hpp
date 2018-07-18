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
void Sutter(Node<Type> * & list) {
    while (list != NULL) {
        Node<Type> * temp = new Node<Type>;
        temp -> value = list -> value;
        temp -> next = list -> next;
        list -> next = temp;
        list = temp -> next;
    }
}

template <typename Type>
Node<Type> * CreateList(vector<Type> & v) {
    // important to initialize the list to NULL.
    Node<Type> * list = new Node<Type>;
    list = NULL;
    // Insert at the beginning.
    for (int i = 0; i < v.size(); ++i) {
        Node<Type> * temp = new Node<Type>;
        temp -> value = v[i];
        temp -> next  = list;
        list = temp;
    }
    return list;
}

template <typename Type>
void PrintList(Node<Type> * & list) {
    if (list != NULL) {
        cout << list -> value << endl;
        PrintList(list -> next);
    }
}

#endif /* utility_hpp */
