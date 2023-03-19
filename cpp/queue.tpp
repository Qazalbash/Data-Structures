/**
 * @file queue.tpp
 * @author Meesum Ali Qazalbash (mesumali26.ma@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

template <typename T>
void linear::Queue<T>::enqueue(const T &value) {
    this->m_queue.push_back(value);
}

template <typename T>
T linear::Queue<T>::dequeue() {
    if (this->m_queue.is_empty()) {
        throw std::out_of_range("linear::Queue<T>::dequeue(): is_empty queue");
    }

    const T value = this->m_queue.front();
    this->m_queue.erase(this->m_queue.begin());
    return value;
}

template <typename T>
bool linear::Queue<T>::is_empty() const {
    return this->m_queue.is_empty();
}

template <typename T>
std::ostream &linear::operator<<(std::ostream &out,
                                 const linear::Queue<T> &queue) {
    auto head = queue.m_queue.begin(), tail = queue.m_queue.end();
    out << "front -> ";
    while (head != tail) out << *(head++) << " -> ";
    out << "back";
    return out;
}