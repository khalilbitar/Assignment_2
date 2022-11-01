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
//overloading + operator
    Stack operator+(Stack& a, Stack& b) {
        Stack c;
        Stack a_temp;
        Stack b_temp;
        while(!a.empty()) {
            a_temp.push(a.top());
            c.push(a.top());
            a.pop();
        }
        while (!b.empty())
        {
            b_temp.push(b.top());
            c.push(b.top());
            b.pop();
        }

        while (!a_temp.empty())
        {
            a.push(a_temp.top());
            a_temp.pop();
        }
         while (!b_temp.empty())
        {
            b.push(b_temp.top());
            b_temp.pop();
        }

        return c;
    }
/*
testing strategy:
printing top on an empty stack
popping an empty stack
pushing to an empty stack
pushing to, popping and printing top of a non empty stack
pushing then printing top
popping then printing top
adding two empty stacks
adding one empty and one non empty stacks
addinf two non empty stacks
adding stacks with different sizes
*/
int main() {
    Stack s;
    //cout<<s.top()<<'\n';
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

    Stack s1;
    s1.push(1);
    s1.push(2);
    Stack s2;
    s2.push(3);
    s2.push(4);
    Stack s3 = s1 + s2;

    while (!s3.empty())
    {
        cout<<s3.top()<<' ';
        s3.pop();
    }
    cout<<'\n';
    
    
    return 0;
}
