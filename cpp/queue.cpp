#include "queue.hpp"

template <typename T>
void Queue<T>::enqueue(const T &value) {
    this->elems.push_back(value);
}

template <typename T>
T Queue<T>::dequeue() {
    if (this->elems.empty())
        throw std::out_of_range("Queue<T>::dequeue(): empty queue");

    const T value = this->elems.front();
    this->elems.erase(this->elems.begin());
    return value;
}

template <typename T>
bool Queue<T>::empty() const {
    return this->elems.empty();
}
