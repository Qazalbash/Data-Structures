#ifndef BST
#define BST

#include <ostream>

template <typename T>
struct Node {
public:

    T        value;
    int      height;
    Node<T> *left, *right;

    Node(const T &);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const Node<U> &);
};

template <typename T>
class BinarySearchTree {
public:

    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const T &);
    void remove(const T &);
    bool contains(const T &) const;

    void inorder() const;
    void preorder() const;
    void postorder() const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &,
                                    const BinarySearchTree<U> &);

protected:

    Node<T> *m_root;

private:

    Node<T> *insert(Node<T> *, const T &);
    Node<T> *remove(Node<T> *, const T &);
    bool     contains(const Node<T> *, const T &) const;

    Node<T> *min(Node<T> *const) const;

    void inorder(Node<T> *) const;
    void preorder(Node<T> *) const;
    void postorder(Node<T> *) const;
};

#include "binary_search_tree.tpp"

#endif  // BST