/**
 * @file heap.hpp
 * @author Meesum Ali Qazalbash (mesumali26.ma@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HEAP
#define HEAP

#include <ostream>
#include <vector>

typedef unsigned long size_t;

/**
 * @brief
 *
 */
namespace graph {

/**
 * @brief
 *
 * @tparam T
 */
template <typename T>
class Heap {
 public:
    /**
     * @brief Construct a new Heap object
     *
     */
    Heap() = default;

    /**
     * @brief Insert the element
     *
     * @param element
     */
    void insert(const T& element);

    /**
     * @brief delete the minimum element
     *
     */
    void delete_min();

    /**
     * @brief get the minimum element
     *
     * @return T
     */
    T extract_min() const;

    /**
     * @brief Size of the heap
     *
     * @return size_t
     */
    size_t size() const;

 private:
    std::vector<T> m_heap;

    /**
     * @brief Get the left child of the parent
     *
     * @param index
     * @return int
     */
    int left(const int index) const;

    /**
     * @brief Get the right child of the parent
     *
     * @param index
     * @return int
     */
    int right(const int index) const;

    /**
     * @brief Get the parent of the child
     *
     * @param index
     * @return int
     */
    int parent(const int index) const;

    /**
     * @brief Heapify the heap from the bottom to the top
     *
     * @param index
     */
    void heapifyup(const int index);

    /**
     * @brief Heapify the heap from the top to the bottom
     *
     * @param index
     */
    void heapifydown(const int index);
};

/**
 * @brief
 *
 * @tparam U
 * @return std::ostream&
 */
template <typename U>
std::ostream& operator<<(std::ostream&, const Heap<U>&);
}  // namespace graph

#include "heap.tpp"

#endif  // HEAP