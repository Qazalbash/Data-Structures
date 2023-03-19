/**
 * @file node.hpp
 * @author Meesum A. Qazalbash (mesumali26.ma@gmail.com)
 * @brief File for the nodes of a graph
 * @version 0.1
 * @date 2023-03-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef NODE
#define NODE

#include <ostream>  // for ostream operator

namespace linear {
/**
 * @brief class for Node data structure
 *
 * @tparam T
 */
template <typename T>
struct Node {
 public:
    T data;
    Node<T>* next;

    /**
     * @brief Construct a new Node object
     */
    Node(const T&);

    /**
     * @brief Construct a new Node object
     */
    Node(const T&, Node<T>*);
};

/**
 * @brief
 *
 * @tparam U
 * @return std::ostream&
 */
template <typename U>
std::ostream& operator<<(std::ostream&, const Node<U>&);

}  // namespace linear

#include "node.tpp"

#endif  // NODE
