#include "node.hpp"

template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr) {}

template <typename T>
Node<T>::Node(const T& data, const Node<T>* next) : data(data), next(next) {}