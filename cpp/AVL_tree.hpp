#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>

#include "bst.hpp"

template <typename T>
class AVL_tree : protected BinarySearchTree<T> {
public:

    /**
     * @brief Construct a new AVL Tree object
     *
     */
    AVL_tree();

    /**
     * @brief Destroy the AVL Tree object
     *
     */
    ~AVL_tree();

    /**
     * @brief Insert a new value into the tree
     *
     * @param value
     */
    void insert(const T &value);

    /**
     * @brief Remove a value from the tree
     *
     * @param value
     */
    void remove(const T &value);

    /**
     * @brief Check if the tree contains a value
     *
     * @param value
     * @return true
     * @return false
     */
    bool contains(const T &value);

    /**
     * @brief Print the tree in order
     *
     */
    void inorder();

    /**
     * @brief Print the tree in preorder
     *
     */
    void preorder();

    /**
     * @brief Print the tree in postorder
     *
     */
    void postorder();

protected:

    /**
     * @brief Get the height of a node
     *
     * @param node
     * @return int
     */
    int height(Node<T> *node);

    /**
     * @brief Get the balance factor of a node
     *
     * @param node
     * @return int
     */
    int balance_factor(Node<T> *node);

    /**
     * @brief Get the left child of a node
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *left_child(Node<T> *node);

    /**
     * @brief Get the right child of a node
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *right_child(Node<T> *node);

    /**
     * @brief Get the left grandchild of a node
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *left_grandchild(Node<T> *node);

    /**
     * @brief Get the right grandchild of a node
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *right_grandchild(Node<T> *node);

    /**
     * @brief Rotate a node to the left
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *rotate_left(Node<T> *node);

    /**
     * @brief Rotate a node to the right
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *rotate_right(Node<T> *node);

    /**
     * @brief Balance a node
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *balance(Node<T> *node);

    /**
     * @brief Insert a new value into the tree
     *
     * @param node
     * @param value
     * @return Node<T>*
     */
    Node<T> *insert(Node<T> *node, const T &value);

    /**
     * @brief Remove a value from the tree
     *
     * @param node
     * @param value
     * @return Node<T>*
     */
    Node<T> *remove(Node<T> *node, const T &value);

    /**
     * @brief Find the minimum
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *minimum(Node<T> *node);

    /**
     * @brief Find the maximum
     *
     * @param node
     * @return Node<T>*
     */
    Node<T> *maximum(Node<T> *node);

    /**
     * @brief Print the tree in a graphical format
     *
     * @param node
     * @param level
     */
    void print(Node<T> *node, int level);

private:

    /**
     * @brief The root of the tree
     *
     */
    Node<T> *root;
};

#endif  // AVL_TREE
