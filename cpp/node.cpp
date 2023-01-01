#include "node.hpp"

template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr) {}

template <typename T>
Node<T>::Node(const T& data, const Node<T>* next) : data(data), next(next) {}

// #include <cstdlib>
// #include <iostream>

// int main() {
//     srand(time(0));

//     Node<int> *node = new Node<int>(rand() % 10);
//     Node<int> *temp = node;
//     for (int i = 0; i < 10; i++) {
//         node->next = new Node<int>(rand() % 10);
//         node       = node->next;
//     }

//     while (temp != nullptr) {
//         std::cout << temp->value << ", ";
//         temp = temp->next;
//     }
//     std::cout << std::endl;

//     delete node;
//     delete temp;

//     return 0;
// }
