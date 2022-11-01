template <class T>
class Btree;

template <class T>
class treeNode {
    friend class Btree<T>;
private:
    T data;
    treeNode<T> * left;
    treeNode<T> * right;
    treeNode(T& d): data(d), left(0), right(0){}
    ~treeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
public:
    const T& getData() const {return data;}
};