#include "queue.hpp"

template <typename T>
void Queue<T>::enqueue(const T value) {
    elems.push_back(value);
}

template <typename T>
T Queue<T>::dequeue() {
    if (elems.empty()) {
        throw std::out_of_range("Queue<>::dequeue(): empty queue");
    }
    T value = elems.front();
    elems.erase(elems.begin());
    return value;
}

template <typename T>
bool Queue<T>::empty() const {
    return elems.empty();
}

int main() {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    while (!queue.empty()) {
        std::cout << queue.dequeue() << " ";
    }
    return 0;
}
