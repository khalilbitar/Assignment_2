#include "my_stack.h"
#include <iostream>
#include <vector>
using namespace std;

bool Stack::empty() const {
    return s.size() == 0;
}

void Stack::push(const int& x) {
    s.push_back(x);
}

int& Stack::top() {
    return s.back();
}

void Stack::pop() {
    s.pop_back();
}
/*
testing strategy:
printing top on an empty stack
popping an empty stack
pushing to an empty stack
pushing to, popping and printing top of a non empty stack
pushing then printing top
popping then printing top
*/
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<'\n';
    s.pop();
    cout<<s.top()<<'\n';
    s.push(3);
    cout<<s.top()<<'\n';
    s.pop();
    if(s.empty())
        cout<<"true"<<'\n';
    else
        cout<<"false"<<'\n';
    s.pop();
    if(s.empty())
        cout<<"true"<<'\n';
    else
        cout<<"false"<<'\n';
    return 0;
}
