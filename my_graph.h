#include "graphNode.h"

class Graph{
    private:
        vector<graphNode> starts;
        vector<graphNode> ends;
    public:
        //requires: two vectors of graphNodes having same size
        //effects: constructs a graph from the given vectors
        Graph(const vector<graphNode>& starts, const vector<graphNode>& ends);
        //requires: a node ID present int the graph
        //effects: returns the number of out going edges from the given node
        int numOutgoing(const int nodeID);
        //requires: a node ID present in the graph
        //effects: returns a vector of adjacent nodes for the given node;
        vector<int> adjacent(const int nodeID) const;
};