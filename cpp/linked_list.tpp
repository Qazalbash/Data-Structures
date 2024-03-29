template <typename T>
linear::SinglyLinkedList<T>::SinglyLinkedList() : m_head(nullptr), m_size(0UL) {}

template <typename T>
linear::SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList& other) {
    this->m_head = nullptr;
    this->m_size = 0UL;

    linear::Node<T>* current = other.m_head;
    linear::Node<T>* newNode = new linear::Node<T>(current->data);
    this->m_head = newNode;
    while (current != nullptr) {
        // this->push_back(current->data);
        newNode->data = current->data;
        newNode->next = current->next;
        current = current->next;
        ++m_size;
    }
}

template <typename T>
linear::SinglyLinkedList<T>::~SinglyLinkedList() {
    this->clear();
}

template <typename T>
void linear::SinglyLinkedList<T>::insert(const size_t index, const T& data) {
    if (index < 0 || index > m_size) {
        return;
    }

    if (index == 0) {
        push(data);
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
void linear::SinglyLinkedList<T>::remove(const size_t index) {
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
int linear::SinglyLinkedList<T>::size() const {
    return m_size;
}

template <typename T>
bool linear::SinglyLinkedList<T>::is_empty() const {
    return m_size == 0;
}

template <typename T>
void linear::SinglyLinkedList<T>::clear() {
    while (this->m_head != nullptr) {
        linear::Node<T>* temp = this->m_head;
        this->m_head = this->m_head->next;
        delete temp;
        --m_size;
    }
}

template <typename T>
void linear::SinglyLinkedList<T>::push(const T& data) {
    linear::Node<T>* newNode = new linear::Node<T>(data);
    newNode->next = m_head;
    m_head = newNode;
    ++m_size;
}

template <typename T>
linear::SinglyLinkedList<T>& linear::SinglyLinkedList<T>::operator=(const SinglyLinkedList& other) {
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
bool linear::SinglyLinkedList<T>::operator==(const SinglyLinkedList& other) const {
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
bool linear::SinglyLinkedList<T>::operator!=(const SinglyLinkedList& other) const {
    return !(*this == other);
}

template <typename T>
T linear::SinglyLinkedList<T>::operator[](const size_t index) const {
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
std::ostream& linear::operator<<(std::ostream& out, const linear::SinglyLinkedList<T>& list) {
    linear::Node<T>* current = list.m_head;
    out << "head -> ";
    while (current != nullptr) {
        out << current->data << " -> ";
        current = current->next;
    }
    out << "tail";
    return out;
}