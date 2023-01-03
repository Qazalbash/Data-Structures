#ifndef AVL_TREE
#define AVL_TREE

#include "bst.hpp"

template <typename T>
class AVLTree : protected BinarySearchTree<T> {
public:

    AVLTree();
    ~AVLTree();

    void insert(const T &value);
    void remove(const T &value);
    bool contains(const T &value) const;
    void inorder() const;
    void preorder() const;
    void postorder() const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream     &os,
                                    const AVLTree<U> &avltree);

protected:

    Node<T> *root;

    int height(const Node<T> *node) const;
    int balance_factor(Node<T> *node);

    Node<T> *left_child(Node<T> *node) const;
    Node<T> *right_child(Node<T> *node) const;
    Node<T> *rotate_left(Node<T> *node);
    Node<T> *rotate_right(Node<T> *node);
    Node<T> *balance(Node<T> *node);
    Node<T> *insert(Node<T> *node, const T &value);
    Node<T> *remove(Node<T> *node, const T &value);
    Node<T> *minimum(Node<T> *node) const;
    Node<T> *maximum(Node<T> *node) const;
};

#include "AVL_tree.tpp"

#endif  // AVL_TREE
