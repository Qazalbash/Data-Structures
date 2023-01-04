#ifndef AVL_TREE
#define AVL_TREE

#include "binary_search_tree.hpp"

template <typename T>
class AVLTree : protected BinarySearchTree<T> {
public:

    AVLTree();
    ~AVLTree();

    void insert(const T &);
    void remove(const T &);
    bool contains(const T &) const;

    void inorder() const;
    void preorder() const;
    void postorder() const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const AVLTree<U> &);

protected:

    Node<T> *m_root;

    int height(const Node<T> *) const;

    int      balance_factor(Node<T> *);
    Node<T> *balance(Node<T> *);

    Node<T> *left_child(Node<T> *) const;
    Node<T> *right_child(Node<T> *) const;

    Node<T> *rotate_left(Node<T> *);
    Node<T> *rotate_right(Node<T> *);

    Node<T> *insert(Node<T> *, const T &);
    Node<T> *remove(Node<T> *, const T &);
};

#include "avl_tree.tpp"

#endif  // AVL_TREE
