template <typename T>
void Queue<T>::enqueue(const T &value) {
        this->m_queue.push_back(value);
}

template <typename T>
T Queue<T>::dequeue() {
        if (this->m_queue.is_empty()) throw std::out_of_range("Queue<T>::dequeue(): is_empty queue");

        const T value = this->m_queue.front();
        this->m_queue.erase(this->m_queue.begin());
        return value;
}

template <typename T>
bool Queue<T>::is_empty() const {
        return this->m_queue.is_empty();
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Queue<T> &queue) {
        auto head = queue.m_queue.begin(), tail = queue.m_queue.end();
        out << "front -> ";
        while (head != tail) out << *(head++) << " -> ";
        out << "back";
        return out;
}