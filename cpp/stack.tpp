template <typename T>
void Stack<T>::push(const T& element) {
        this->m_stack.push_back(element);
}

template <typename T>
void Stack<T>::pop() {
        assert(!this->m_stack.empty());
        this->m_stack.pop_back();
}

template <typename T>
T Stack<T>::top() const {
        assert(!this->m_stack.empty());
        return this->m_stack.back();
}

template <typename T>
bool Stack<T>::empty() const {
        return this->m_stack.empty();
}

template <typename T>
Stack<T>::Stack(Stack<T> const& other) {
        this->m_stack = other.m_stack;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> const& other) {
        if (this != &other) this->m_stack = other.m_stack;
        return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        auto head = stack.m_stack.begin(), tail = stack.m_stack.end();
        os << "top -> ";
        while (head != tail) os << *(--tail) << " -> ";
        os << "bottom";
        return os;
}