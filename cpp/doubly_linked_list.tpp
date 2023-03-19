template <typename T>
linear::DoublyLinkedList<T>::DoublyLinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0UL) {}

template <typename T>
linear::DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) {
    this->m_head = nullptr;
    this->m_tail = nullptr;
    this->m_size = 0UL;

    linear::Node<T>* current = other.m_head;
    linear::Node<T>* newNode = new linear::Node<T>(current->data);
    this->m_head = newNode;
    while (current != nullptr) {
        newNode->data = current->data;
        newNode->next = current->next;
        current = current->next;
        ++m_size;
    }
    this->m_tail = newNode;
}

template <typename T>
linear::DoublyLinkedList<T>::~DoublyLinkedList() {
    this->clear();
}

template <typename T>
void linear::DoublyLinkedList<T>::insert(const size_t index, const T& data) {
    if (index < 0 || index > m_size) {
        return;
    }

    if (index == 0) {
        push_front(data);
    } else {
        linear::Node<T>* current = this->m_head;

        for (size_t i = 0UL; i + 1 < index; ++i) {
            current = current->next;
        }

        linear::Node<T>* newNode = new linear::Node<T>(data);
        newNode->next = current->next;
        current->next = newNode;
        ++m_size;
    }
}

template <typename T>
void linear::DoublyLinkedList<T>::remove(const size_t index) {
    if (index < 0 || index >= m_size || this->m_head == nullptr) {
        return;
    }
    if (index == 0) {
        linear::Node<T>* temp = this->m_head;
        this->m_head = this->m_head->next;
        delete temp;
        --m_size;
    } else {
        linear::Node<T>* current = this->m_head;

        for (size_t i = 0UL; i + 1 < index; ++i) {
            current = current->next;
        }
        linear::Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        --m_size;
    }
}

template <typename T>
int linear::DoublyLinkedList<T>::size() const {
    return m_size;
}

template <typename T>
bool linear::DoublyLinkedList<T>::is_empty() const {
    return m_size == 0;
}

template <typename T>
void linear::DoublyLinkedList<T>::clear() {
    while (this->m_head != nullptr) {
        linear::Node<T>* temp = this->m_head;
        this->m_head = this->m_head->next;
        delete temp;
        --m_size;
    }
}

template <typename T>
void linear::DoublyLinkedList<T>::push_front(const T& data) {
    linear::Node<T>* newNode = new linear::Node<T>(data);
    newNode->next = m_head;
    m_head = newNode;
    ++m_size;
}

template <typename T>
void linear::DoublyLinkedList<T>::push_back(const T& data) {
    if (m_head == nullptr) {
        m_head = new linear::Node<T>(data);
    } else {
        linear::Node<T>* current = m_head;
        while (current->next != nullptr) current = current->next;
        current->next = new linear::Node<T>(data);
    }
    ++m_size;
}

template <typename T>
linear::DoublyLinkedList<T>& linear::DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
    if (this == &other) {
        return *this;
    }

    this->clear();

    linear::Node<T>* current = other.m_head;
    linear::Node<T>* newNode = new linear::Node<T>(current->data);
    this->m_head = newNode;
    while (current != nullptr) {
        // this->push_back(current->data);
        newNode->data = current->data;
        newNode->next = current->next;
        current = current->next;
    }

    return *this;
}

template <typename T>
bool linear::DoublyLinkedList<T>::operator==(const DoublyLinkedList& other) const {
    if (m_size != other.m_size) {
        return false;
    }

    linear::Node<T>* current1 = m_head;
    linear::Node<T>* current2 = other.m_head;
    while (current1 != nullptr) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

template <typename T>
bool linear::DoublyLinkedList<T>::operator!=(const DoublyLinkedList& other) const {
    return !(*this == other);
}

template <typename T>
T linear::DoublyLinkedList<T>::operator[](const size_t index) const {
    if (index < 0 || index >= m_size) {
        return T();
    }
    linear::Node<T>* current = this->m_head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
std::ostream& linear::operator<<(std::ostream& out, const linear::DoublyLinkedList<T>& list) {
    linear::Node<T>* current = list.m_head;
    out << "head -> ";
    while (current != nullptr) {
        out << current->data << " -> ";
        current = current->next;
    }
    out << "tail";
    return out;
}