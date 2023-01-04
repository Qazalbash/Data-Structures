#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <vector>

template <typename T>
class Queue {
public:

    Queue() = default;

    void enqueue(const T &);
    T    dequeue();
    bool is_empty() const;

    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const Queue<U> &);

private:

    std::vector<T> m_queue;
};

#include "queue.tpp"

#endif  // QUEUE