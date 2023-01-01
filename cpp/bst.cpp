#include "bst.hpp"

#include <iostream>

template <typename T>
Node<T>::Node(const T &value) : value(value), left(nullptr), right(nullptr) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

template <typename T>
void BinarySearchTree<T>::insert(const T &value) {
    root = insert(root, value);
}

template <typename T>
void BinarySearchTree<T>::remove(const T &value) {
    root = remove(root, value);
}

template <typename T>
bool BinarySearchTree<T>::contains(const T &value) {
    return contains(root, value);
}

template <typename T>
Node<T> *BinarySearchTree<T>::insert(Node<T> *node, const T &value) {
    if (node == nullptr) return new Node<T>(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    return node;
}

template <typename T>
Node<T> *BinarySearchTree<T>::remove(Node<T> *node, const T &value) {
    if (node == nullptr) return nullptr;

    if (value < node->value)
        node->left = remove(node->left, value);
    else if (value > node->value)
        node->right = remove(node->right, value);
    else {
        if (node->left == nullptr) {
            Node<T> *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T> *temp = node->left;
            delete node;
            return temp;
        }

        Node<T> *temp = min(node->right);
        node->value   = temp->value;
        node->right   = remove(node->right, temp->value);
    }

    return node;
}

template <typename T>
bool BinarySearchTree<T>::contains(const Node<T> *node, const T &value) {
    while (node != nullptr) {
        if (value < node->value)
            node = node->left;
        else if (value > node->value)
            node = node->right;
        else
            return true;
    }
    return false;
}

template <typename T>
Node<T> *BinarySearchTree<T>::min(Node<T> *const node) {
    Node<T> *current = node;

    while (current->left != nullptr) current = current->left;

    return current;
}

template <typename T>
void BinarySearchTree<T>::inorder() {
    inorder(root);
}

template <typename T>
void BinarySearchTree<T>::inorder(Node<T> *node) {
    if (node == nullptr) return;

    inorder(node->left);
    std::cout << node->value << " ";
    inorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::preorder() {
    preorder(root);
}

template <typename T>
void BinarySearchTree<T>::preorder(Node<T> *node) {
    if (node == nullptr) return;

    std::cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::postorder() {
    postorder(root);
}

template <typename T>
void BinarySearchTree<T>::postorder(Node<T> *node) {
    if (node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    std::cout << node->value << " ";
}

int main() {
    BinarySearchTree<int> bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    bst.inorder();
    std::cout << std::endl;

    bst.preorder();
    std::cout << std::endl;

    bst.postorder();
    std::cout << std::endl;
    return 0;
}