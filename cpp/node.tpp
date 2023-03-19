/**
 * @file node.tpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */

template <typename T>
graph::linear::Node<T>::Node(const T& data) : data(data), next(nullptr) {}

template <typename T>
graph::linear::Node<T>::Node(const T& data, graph::linear::Node<T>* next)
    : data(data), next(next) {}

template <typename T>
std::ostream& graph::linear::operator<<(std::ostream& out,
                                        const Node<T>& node) {
    out << node.data;
    return out;
}