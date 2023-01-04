template <typename T>
LinkedList<T>::LinkedList() : m_head(nullptr), m_size(0) {}

template <typename T>
LinkedList<T>::LinkedList(const T& data)
    : m_head(new Node<T>(data)), m_size(1) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    this->m_head = nullptr;
    this->m_size = 0;

    Node<T>* current = other.m_head;
    Node<T>* newNode = new Node<T>(current->data);
    this->m_head     = newNode;
    while (current != nullptr) {
        // this->push_back(current->data);
        newNode->data = current->data;
        newNode->next = current->next;
        current       = current->next;
        m_size++;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    this->clear();
}

template <typename T>
void LinkedList<T>::insert(const size_t& index, const T& data) {
    if (index < 0 || index > m_size) return;

    if (index == 0)
        push_front(data);
    else {
        Node<T>* current = this->m_head;

        for (size_t i = 0; i < index - 1; ++i) current = current->next;

        Node<T>* newNode = new Node<T>(data);
        newNode->next    = current->next;
        current->next    = newNode;
        ++m_size;
    }
}

template <typename T>
void LinkedList<T>::remove(const size_t& index) {
    if (index < 0 || index >= m_size || this->m_head == nullptr) return;

    if (index == 0) {
        Node<T>* temp = this->m_head;
        this->m_head  = this->m_head->next;
        delete temp;
        --m_size;
    } else {
        Node<T>* current = this->m_head;

        for (size_t i = 0; i + 1 < index; ++i) current = current->next;

        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        --m_size;
    }
}

template <typename T>
int LinkedList<T>::size() const {
    return m_size;
}

template <typename T>
bool LinkedList<T>::is_empty() const {
    return m_size == 0;
}

template <typename T>
void LinkedList<T>::clear() {
    while (this->m_head != nullptr) {
        Node<T>* temp = this->m_head;
        this->m_head  = this->m_head->next;
        delete temp;
        --m_size;
    }
}

template <typename T>
void LinkedList<T>::push_front(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next    = m_head;
    m_head           = newNode;
    ++m_size;
}

template <typename T>
void LinkedList<T>::push_back(const T& data) {
    if (m_head == nullptr)
        m_head = new Node<T>(data);
    else {
        Node<T>* current = m_head;
        while (current->next != nullptr) current = current->next;
        current->next = new Node<T>(data);
    }
    ++m_size;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this == &other) return *this;

    this->clear();

    Node<T>* current = other.m_head;
    Node<T>* newNode = new Node<T>(current->data);
    this->m_head     = newNode;
    while (current != nullptr) {
        // this->push_back(current->data);
        newNode->data = current->data;
        newNode->next = current->next;
        current       = current->next;
    }

    return *this;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList& other) const {
    if (m_size != other.m_size) return false;

    Node<T>* current1 = m_head;
    Node<T>* current2 = other.m_head;
    while (current1 != nullptr) {
        if (current1->data != current2->data) return false;
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

template <typename T>
bool LinkedList<T>::operator!=(const LinkedList& other) const {
    return !(*this == other);
}

template <typename T>
T LinkedList<T>::operator[](const size_t& index) const {
    if (index < 0 || index >= m_size) return T();
    Node<T>* current = this->m_head;
    for (int i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template <typename T>
T& LinkedList<T>::operator[](const size_t& index) {
    if (index < 0 || index >= m_size) return T();
    Node<T>* current = this->m_head;
    for (int i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {
    Node<T>* current = list.m_head;
    out << "head -> ";
    while (current != nullptr) {
        out << current->data << " -> ";
        current = current->next;
    }
    out << "tail";
    return out;
}