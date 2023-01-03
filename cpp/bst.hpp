#ifndef BST
#define BST

template <typename T>
struct Node {
    T        value;
    int      height;
    Node<T> *left, *right;

    Node(const T &value);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Node<U> &node);
};

template <typename T>
class BinarySearchTree {
public:

    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const T &value);
    void remove(const T &value);
    bool contains(const T &value) const;

    void inorder() const;
    void preorder() const;
    void postorder() const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream              &os,
                                    const BinarySearchTree<U> &bst);

protected:

    Node<T> *root;

private:

    Node<T> *insert(Node<T> *node, const T &value);
    Node<T> *remove(Node<T> *node, const T &value);
    bool     contains(const Node<T> *node, const T &value) const;

    Node<T> *min(Node<T> *const node) const;

    void inorder(Node<T> *node) const;
    void preorder(Node<T> *node) const;
    void postorder(Node<T> *node) const;
};

#include "bst.tpp"

#endif  // BST