#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    vector<int> s;
public:
    //requires: nothing
    //effects: returns true if stack is empty and false otherwise
    bool empty() const;
    //requires: constant reference to an integer
    //effects: pushes the integer to the top of the stack
    void push(const int&);
    //requires: nothing
    //effects: returns the element on the top of the stack
    int& top();
    //requires: nothing
    //effects: pops element recently added to stack
    void pop();
};

