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
void Stutter(Node<Type> * & list) {
    Node<Type> * itr = list;
    while (itr != NULL) {
        Node<Type> * temp = new Node<Type>;
        temp -> value = itr -> value;
        temp -> next = itr -> next;
        itr -> next = temp;
        itr = temp -> next;
    }
}

template <typename Type>
Node<Type> * CreateList(vector<Type> & v, int i=0) {
    if (v.size() == i) return NULL;
    Node<Type> * list = new Node<Type>;
    list -> value = v[i];
    list -> next = CreateList(v, i+1);
    return list;
}

template <typename Type>
void PrintList(Node<Type> * & list) {
    if (list != NULL) {
        cout << list -> value << endl;
        PrintList(list -> next);
    }
}

template <typename Type>
void Unstutter(Node<Type> * & list) {
    Node<Type> * back, * front;
    back = list;
    if (list != NULL) {
        front = back -> next;
        while( front != NULL) {
            if (front -> value == back -> value) {
                Node<Type> * temp = front;
                front = front -> next;
                delete temp;
                back -> next = front;
            } else {
                back = back -> next;
                front = front -> next;
            }
        }
    }
}

#endif /* utility_hpp */
