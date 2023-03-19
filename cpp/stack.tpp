template <typename T>
void linear::Stack<T>::push(const T& element) {
    this->m_stack.push_back(element);
}

template <typename T>
void linear::Stack<T>::pop() {
    assert(!this->m_stack.empty());
    this->m_stack.pop_back();
}

template <typename T>
T linear::Stack<T>::top() const {
    assert(!this->m_stack.empty());
    return this->m_stack.back();
}

template <typename T>
bool linear::Stack<T>::empty() const {
    return this->m_stack.empty();
}

template <typename T>
linear::Stack<T>::Stack(linear::Stack<T> const& other) {
    this->m_stack = other.m_stack;
}

template <typename T>
linear::Stack<T>& linear::Stack<T>::operator=(linear::Stack<T> const& other) {
    if (this != &other)
        this->m_stack = other.m_stack;
    return *this;
}

template <typename T>
std::ostream& linear::operator<<(std::ostream& os, const linear::Stack<T>& stack) {
    auto head = stack.m_stack.begin(), tail = stack.m_stack.end();
    os << "top -> ";
    while (head != tail) os << *(--tail) << " -> ";
    os << "bottom";
    return os;
}