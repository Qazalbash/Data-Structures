/**
 * @file avl_tree.hpp
 * @author Meesum Ali Qazalbash (mesumali26.ma@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVL_TREE
#define AVL_TREE

#include "binary_search_tree.hpp"

/**
 * @brief Namespace for graph data structures.
 */
namespace graph {

/**
 * @brief AVL Tree class.
 *
 * @tparam T
 */
template <typename T>
class AVLTree : protected BinarySearchTree<T> {
 public:
    /**
     * @brief Construct a new AVLTree object
     *
     */
    AVLTree();

    /**
     * @brief Construct a new AVLTree object
     *
     * @param avl_tree
     */
    AVLTree(const AVLTree<T> &avl_tree);

    /**
     * @brief Destroy the AVLTree object
     *
     */
    ~AVLTree();

    /**
     * @brief Insert an element into the tree.
     *
     * @param element
     */
    void insert(const T &element);

    /**
     * @brief Remove an element from the tree.
     *
     * @param element
     */
    void remove(const T &element);

    /**
     * @brief Check if the tree contains an element.
     *
     * @param element
     * @return bool
     */
    bool contains(const T &element) const;

    /**
     * @brief Inorder traversal of the tree.
     *
     */
    void inorder() const;

    /**
     * @brief Preorder traversal of the tree.
     *
     */
    void preorder() const;

    /**
     * @brief Postorder traversal of the tree.
     *
     */
    void postorder() const;

 protected:
    binary::Node<T> *m_root;  // Root of the tree.

    /**
     * @brief Get the height of a node.
     *
     * @param node
     * @return int
     */
    int height(const binary::Node<T> *node) const;

    /**
     * @brief Balance factor of a node.
     *
     * @param node
     * @return int
     */
    int balance_factor(binary::Node<T> *node);

    /**
     * @brief Balance the tree.
     *
     * @param node
     * @return binary::Node<T>*
     */
    binary::Node<T> *balance(binary::Node<T> *node);

    /**
     * @brief Get the left child of a node.
     *
     * @param node
     * @return binary::Node<T>*
     */
    binary::Node<T> *left_child(binary::Node<T> *node) const;

    /**
     * @brief Get the right child of a node.
     *
     * @param node
     * @return binary::Node<T>*
     */
    binary::Node<T> *right_child(binary::Node<T> *node) const;

    /**
     * @brief Rotate the tree to the left.
     *
     * @param node
     * @return binary::Node<T>*
     */
    binary::Node<T> *rotate_left(binary::Node<T> *node);

    /**
     * @brief Rotate the tree to the right.
     *
     * @param node
     * @return binary::Node<T>*
     */
    binary::Node<T> *rotate_right(binary::Node<T> *node);

    /**
     * @brief Insert an element into the tree.
     *
     * @param node
     * @param element
     * @return binary::Node<T>*
     */
    binary::Node<T> *insert(binary::Node<T> *node, const T &element);

    /**
     * @brief Remove an element from the tree.
     *
     * @param node
     * @param element
     * @return binary::Node<T>*
     */
    binary::Node<T> *remove(binary::Node<T> *node, const T &element);
};

/**
 * @brief Overload the << operator for AVLTree.
 *
 * @tparam U
 * @param out
 * @param tree
 * @return std::ostream&
 */
template <typename U>
std::ostream &operator<<(std::ostream &out, const AVLTree<U> &tree);

}  // namespace graph

#include "avl_tree.tpp"

#endif  // AVL_TREE
