#include "treeNode.h"

template <class T>
class Btree {
private:
    treeNode<T> * root;
    bool addNode(treeNode<T> *, T&);
    bool deleteNode(treeNode<T> *, T&);
    int treeSize(treeNode<T> *, int&);
    int subtreeSize(treeNode<T> *);
    void postOrderPrint(treeNode<T> *);
    void preOrderPrint(treeNode<T> *);
    void inOrderPrint(treeNode<T> *);

public:
    Btree(): root(0) {}
    //requires: nothing
    //effects: add a node with the given data
    void addNode(T&);
    //requires: nothing
    //effects: deletes node with given data or prints an error if data not found
    void deleteNode(T&);
    //requires: nothing
    //effects: returns number of nodes in the tree
    int treeSize();
    //requires: nothing
    //effects: returns size of subtree with the given data or 0 if data not found
    int subtreeSize(T&);
    //requires: nothing
    //effects: does a post order traversal on tree
    void postOrderPrint();
    //requires: nothing
    //effects: does a pre order traversal on tree
    void preOrderPrint();
    //requires: nothing
    //effects: does an in order traversal on tree
    void inOrderPrint();
};