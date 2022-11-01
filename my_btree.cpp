#include "my_btree.h"
#include <iostream>
using namespace std;

template <class T>
bool Btree<T>::addNode(treeNode<T> * node, T& x) {
    if(node->left == 0 && node->right == 0) {
        node->left = new treeNode<T>(x);
        return true;
    }
    else if (node->left != 0 && node->right == 0) {
        node->right = new treeNode<T>(x);
        return true;
    }
    else {
        if(!addNode(node->left, x));
            addNode(node->right, x);
    }
}

template <class T>
void Btree<T>::addNode(T& x) {
    if(root == 0)
        root = new treeNode<T>(x);
    else {
        addNode(root, x);
    }
}

template <class T>
bool Btree<T>::deleteNode(treeNode<T> * node, T& x) {
    if(node->left == 0 && node->right == 0) {
        if(node->data == x) {
            delete node;
            return true;
        }
        return false;
    } else {
        if(!(deleteNode(node->left, x)))
            deleteNode(node->right, x);
    }
    return false;
}

template <class T>
void Btree<T>::deleteNode(T& x) {
    if(!deleteNode(root, x))
        cout<<"CANNOT DELETE NODE"<<endl;
}

template <class T>
int Btree<T>::treeSize(treeNode<T>* node, int& counter) {
    if(node != 0)
        counter++;
    counter += treeSize(node->left, counter) + treeSize(node->right, counter);
    return counter;
}

template <class T>
int Btree<T>::treeSize() {
    int c = 0;
    return treeSize(root, c);
}

template <class T>
int Btree<T>::subtreeSize(treeNode<T> * node) {
    int c = 0;
    return treeSize(node, c);
}

template <class T>
int Btree<T>::subtreeSize(T& x) {
    int c = 0;
    treeNode<T> * n = root;
    if(n->data == x)
        return treeSize(n, c);
    else
        return subtreeSize(n->left) + subtreeSize(n->right);
}

template <class T>
void Btree<T>::postOrderPrint(treeNode<T> * node) {
    if(node == 0)
        return;
    if(node->left == 0 && node->right == 0)
        cout<<node->data<<' ';
    else
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        cout<<node->data<<' ';
}

template <class T>
void Btree<T>::postOrderPrint() {
    postOrderPrint(root);
}

template <class T>
void Btree<T>::preOrderPrint(treeNode<T> * node) {
    if(node == 0)
        return;
    if(node->left == 0 && node->right == 0)
        cout<<node->data<<' ';
    else
        cout<<node->data<<' ';
        preOrderPrint(node->left);
        preOrderPrint(node->right);
}

template <class T>
void Btree<T>::preOrderPrint() {
    preOrderPrint(root);
}

template <class T>
void Btree<T>::inOrderPrint(treeNode<T> * node) {
    if(node == 0)
        return;
    if(node->left == 0 && node->right == 0)
        cout<<node->data<<' ';
    else
        inOrderPrint(node->left);
        cout<<node->data<<' ';
        inOrderPrint(node->right);
}

template <class T>
void Btree<T>::inOrderPrint() {
    inOrderPrint(root);
}

template class Btree<int>;
template class Btree<char>;
/*
testing strategy:
adding to an empty tree + a tree with one node + a complete tree + a tree that needs one more node to be complete
printing(post, in, and pre) an empty tree + a tree with one node
deleting node of an empty tree
deleting a node that doesn't exist
size of an empty tree
size of a tree with one node
size of subtree of root
size of subtree of a non-existent root
*/
int main() {
    Btree<int> bt;
    int x = 1;
    bt.addNode(x);
    bt.deleteNode(x);
    int y = 2;
    int z = 3;
    int m = 4;
    bt.addNode(y);
    bt.addNode(z);
    bt.addNode(m);
    bt.postOrderPrint();
    bt.preOrderPrint();
    bt.inOrderPrint();
    return 0;
}