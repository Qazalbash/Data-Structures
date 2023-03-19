/**
 * @file queue.hpp
 * @author Meesum Ali Qazalbash (mesumali26.ma@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <vector>

/**
 * @brief Namespace for linear data structures
 */
namespace linear {

/**
 * @brief Class for Queues
 *
 * @tparam T
 */
template <typename T>
class Queue {
 public:
    /**
     * @brief Construct a new Queue object
     *
     */
    Queue() = default;

    /**
     * @brief Enqueue method
     *
     */
    void enqueue(const T &);

    /**
     * @brief Dequeue method
     *
     * @return T
     */
    T dequeue();

    /**
     * @brief Checking if queue is empty
     *
     * @return bool
     */
    bool is_empty() const;

 private:
    std::vector<T> m_queue;
};

/**
 * @brief Ostream operator
 *
 * @tparam U
 * @return std::ostream&
 */
template <typename U>
std::ostream &operator<<(std::ostream &, const Queue<U> &);

}  // namespace linear

#include "queue.tpp"

#endif  // QUEUE