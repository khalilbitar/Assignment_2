#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    vector<int> s;
public:
    bool empty() const;
    void push(const int&);
    int& top();
    void pop();
};

