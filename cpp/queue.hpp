#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <vector>

/**
 * @brief Queue - Queue class
 * @param front - Pointer to the front of the queue
 * @param back - Pointer to the back of the queue
 *
 * @tparam T - Type of the value to be stored in the queue
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
     * @brief Enqueue - Enqueues a value to the back of the queue
     *
     * @param value - Value to be enqueued to the queue
     */
    void enqueue(const T &value);

    /**
     * @brief Dequeue - Dequeues the front value from the queue
     *
     * @return T - Value dequeued from the queue
     */
    T dequeue();

    /**
     * @brief Empty - Checks if the queue is empty
     *
     * @return true
     * @return false
     */
    bool empty() const;

private:

    std::vector<T> elems;
};

#endif  // QUEUE