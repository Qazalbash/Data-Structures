/**
 * @file binary_search_tree.hpp
 * @author Meesum Ali Qazalbash (mesumali26.ma@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BST
#define BST

#include <iostream>

/**
 * @brief Namespace for binary
 *
 */
namespace binary {

/**
 * @brief Binary Node class
 *
 * @tparam T
 */
template <typename T>
struct Node {
 public:
    T value;
    int height;
    binary::Node<T> *left, *right;

    /**
     * @brief Construct a new Node object
     *
     * @param value
     */
    Node(const T &value);

    /**
     * @brief Construct a new Node object
     *
     * @param node
     */
    Node(const Node<T> &node);

    /**
     * @brief Destroy the Node object
     *
     */
    ~Node();
};

/**
 * @brief Overload the << operator for Node
 *
 * @tparam U
 * @param os
 * @param node
 * @return std::ostream&
 */
template <typename U>
std::ostream &operator<<(std::ostream &os, const Node<U> &node);
}  // namespace binary

/**
 * @brief Namespace for graph data structures
 *
 */
namespace graph {

/**
 * @brief Binary Search Tree class
 *
 * @tparam T
 */
template <typename T>
class BinarySearchTree {
 public:
    /**
     * @brief Construct a new Binary Search Tree object
     *
     */
    BinarySearchTree();

    /**
     * @brief Construct a new Binary Search Tree object
     *
     * @param bst
     */
    BinarySearchTree(const BinarySearchTree<T> &bst);

    /**
     * @brief Destroy the Binary Search Tree object
     *
     */
    ~BinarySearchTree();

    /**
     * @brief Insert an element in the tree
     *
     * @param element
     */
    void insert(const T &element);

    /**
     * @brief Remove an element from the tree
     *
     * @param element
     */
    void remove(const T &element);

    /**
     * @brief Check if an element is present in the tree
     *
     * @param element
     * @return bool
     */
    bool contains(const T &element) const;

    /**
     * @brief Inorder traversal of the tree
     *
     */
    void inorder() const;

    /**
     * @brief Preorder traversal of the tree
     *
     */
    void preorder() const;

    /**
     * @brief Postorder traversal of the tree
     *
     */
    void postorder() const;

 protected:
    binary::Node<T> *m_root;  // root of the tree

 private:
    /**
     * @brief Insert an element in the tree
     *
     * @param node
     * @param element
     * @return binary::Node<T>*
     */
    binary::Node<T> *insert(binary::Node<T> *node, const T &element);

    /**
     * @brief Remove an element from the tree
     *
     * @param node
     * @param element
     * @return binary::Node<T>*
     */
    binary::Node<T> *remove(binary::Node<T> *node, const T &element);

    /**
     * @brief Check if an element is present in the tree
     *
     * @param node
     * @param element
     * @return bool
     */
    bool contains(const binary::Node<T> *node, const T &element) const;

    /**
     * @brief Get the min object
     *
     * @param node
     * @return binary::Node<T>*
     */
    binary::Node<T> *min(binary::Node<T> *const node) const;

    /**
     * @brief Inorder traversal of the tree
     *
     * @param node
     */
    void inorder(binary::Node<T> *node) const;

    /**
     * @brief Preorder traversal of the tree
     *
     * @param node
     */
    void preorder(binary::Node<T> *node) const;

    /**
     * @brief Postorder traversal of the tree
     *
     * @param node
     */
    void postorder(binary::Node<T> *node) const;
};

/**
 * @brief Overload the << operator for BinarySearchTree
 *
 * @tparam U
 * @return std::ostream&
 */
template <typename U>
std::ostream &operator<<(std::ostream &, const BinarySearchTree<U> &);
}  // namespace graph

#include "binary_search_tree.tpp"

#endif  // BST