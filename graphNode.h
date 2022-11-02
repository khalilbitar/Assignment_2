#include <vector>
#include <iostream>
using namespace std;

class graphNode {
    public:
        int data;
        vector<graphNode> adjacentNodes;
        graphNode(int d): data(d){}
        graphNode(int d, vector<graphNode> adjNodes): data(d), adjacentNodes(adjNodes){}
};