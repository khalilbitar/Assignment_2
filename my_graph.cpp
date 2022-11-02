#include "my_graph.h"
#include <stdexcept>
#include<iostream>
using namespace std;

Graph::Graph(const vector<graphNode>& starts, const vector<graphNode>& ends) {
    if(starts.size() != ends.size()) {
        throw invalid_argument("Vectors must be of same lengths!");
    }
    this->starts = starts;
    this->ends = ends;
    for(int i = 0; i < starts.size(); i++) {
        this->starts[i].adjacentNodes.push_back(this->ends[i]);
    } 
}

int Graph::numOutgoing(const int nodeID) {
    int counter = 0;
    for(int i = 0; i < starts.size(); i++) {
        if(starts[i].data == nodeID) {
            counter++;
        }
    }
    return counter;
}

vector<int> Graph::adjacent(const int nodeID) const {
    vector<int> adj;
    for(int i = 0; i < starts.size(); i++) {
        if(starts[i].data == nodeID) {
            for(int j = 0; j < starts[i].adjacentNodes.size(); j++)
                adj.push_back(starts[i].adjacentNodes[j].data);
        }
    }
    return adj;
}

vector<int> Graph::checkCycle() {
    vector<int> cycle;
    for(int i = 0; i < starts.size(); i++) {
        if(starts[i].data == ends[i].data) {
            cycle.push_back(starts[i].data);
            cycle.push_back(starts[i].data);
            return cycle;
        }
    }
}
/*
testing strategy:
constructing a graph from empty vectors, vectors of differrent lengths, and vectors of same elements
constructing a graph by passing the same vector as the two arguments
printing number of outgoing edges for an element not present in the graph, for a graph having one node, for a node having 0 outgoing edges, for a node having outgoing edges to itself
printing adjacency list for the same test inputs above
*/
int main() {
    vector<graphNode> s;
    graphNode g1(0);
    graphNode g2(1);
    graphNode g3(2);
    graphNode g4(4);
    graphNode g5(3);
    s.push_back(g1);
    s.push_back(g1);
    s.push_back(g1);
    s.push_back(g4);
    s.push_back(g4);
    s.push_back(g5);
    vector<graphNode> e;
    e.push_back(g2);
    e.push_back(g3);
    e.push_back(g5);
    e.push_back(g5);
    e.push_back(g2);
    e.push_back(g2);
    Graph g(s, e);
    cout<< g.numOutgoing(4)<<endl;
    vector<int> adj = g.adjacent(0);
    for(int i = 0; i < adj.size(); i++)
        cout<<adj[i]<<' ';
    cout<<endl;
    vector<int> cycles = g.checkCycle();
    for(int i = 0; i < cycles.size(); i++)
        cout<<cycles[i]<<' ';
    cout<<endl;
    return 0;
}
