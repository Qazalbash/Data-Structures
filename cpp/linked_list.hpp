/**
 * @file linked_list.hpp
 * @author Meesum Ali Qazalbash (mesumali26.ma@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.hpp"

typedef unsigned long size_t;

/**
 * @brief Namespace for linear data structures
 *
 */
namespace linear {

/**
 * @brief Singly Linked List class
 *
 * @tparam T
 */
template <typename T>
class SinglyLinkedList {
 public:
    /**
     * @brief Construct a new Linked List object
     *
     */
    SinglyLinkedList();

    /**
     * @brief Construct a new Singly Linked List object
     *
     * @param sll
     */
    SinglyLinkedList(const SinglyLinkedList& sll);

    /**
     * @brief Destroy the Singly Linked List object
     *
     */
    ~SinglyLinkedList();

    /**
     * @brief Insert a new element at given index
     *
     * @param index
     * @param value
     */
    void insert(const size_t index, const T& value);

    /**
     * @brief Remove an element at given index
     *
     * @param index
     */
    void remove(const size_t index);

    /**
     * @brief Get the element at given index
     *
     * @return int
     */
    int size() const;

    /**
     * @brief Check if the list is empty
     *
     * @return bool
     */
    bool is_empty() const;

    /**
     * @brief Clear the list
     *
     */
    void clear();

    /**
     * @brief Push an element at the front of the list
     *
     * @param element
     */
    void push(const T& element);

    /**
     * @brief Overload the = operator
     *
     * @return SinglyLinkedList&
     */
    SinglyLinkedList& operator=(const SinglyLinkedList&);

    /**
     * @brief Overload the == operators
     *
     * @param sll
     * @return bool
     */
    bool operator==(const SinglyLinkedList& sll) const;

    /**
     * @brief Overload the != operators
     *
     * @param sll
     * @return bool
     */
    bool operator!=(const SinglyLinkedList& sll) const;

    /**
     * @brief Overload the [] operator
     *
     * @param index
     * @return T
     */
    T operator[](const size_t index) const;

 private:
    linear::Node<T>* m_head;  // Head of the list
    size_t m_size = 0UL;      // Size of the list
};

template <typename U>
std::ostream& operator<<(std::ostream&, const SinglyLinkedList<U>&);

}  // namespace linear

#include "linked_list.tpp"

#endif  // LINKED_LIST
