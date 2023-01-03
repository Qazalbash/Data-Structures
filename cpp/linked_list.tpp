template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), m_size(0) {}

template <typename T>
LinkedList<T>::LinkedList(const T& data) : head(new Node<T>(data)), m_size(1) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    this->head   = nullptr;
    this->m_size = 0;

    Node<T>* current = other.head;
    while (current != nullptr) {
        this->push_back(current->data);
        current = current->next;
        m_size++;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    this->clear();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this == &other) return *this;

    this->clear();

    Node<T>* current = other.head;
    while (current != nullptr) {
        this->push_back(current->data);
        current = current->next;
    }

    return *this;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList& other) const {
    if (m_size != other.m_size) return false;

    Node<T>* current1 = head;
    Node<T>* current2 = other.head;
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
void LinkedList<T>::push_front(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next    = head;
    head             = newNode;
    ++m_size;
}

template <typename T>
void LinkedList<T>::push_back(const T& data) {
    if (head == nullptr)
        head = new Node<T>(data);
    else {
        Node<T>* current = head;
        while (current->next != nullptr) current = current->next;
        current->next = new Node<T>(data);
    }
    ++m_size;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) return;

    Node<T>* temp = head;
    head          = head->next;
    delete temp;
    --m_size;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (this->head == nullptr) return;

    if (this->head->next == nullptr) {
        delete this->head;
        this->head = nullptr;
    } else {
        Node<T>* current = this->head;
        while (current->next->next != nullptr) current = current->next;
        delete current->next;
        current->next = nullptr;
    }
    --m_size;
}

template <typename T>
T LinkedList<T>::front() const {
    return this->head->data;
}

template <typename T>
T LinkedList<T>::back() const {
    Node<T>* current = this->head;
    while (current->next != nullptr) current = current->next;
    return current->data;
}

template <typename T>
T LinkedList<T>::get(const int& index) const {
    if (index < 0 || index >= m_size) return T();
    Node<T>* current = this->head;
    for (int i = 0; i < index; ++i) current = current->next;
    return current->data;
}

template <typename T>
void LinkedList<T>::set(const int& index, const T& data) {
    if (index < 0 || index >= m_size) return;
    Node<T>* current = this->head;
    for (int i = 0; i < index; ++i) current = current->next;
    current->data = data;
}

template <typename T>
void LinkedList<T>::insert(const size_t& index, const T& data) {
    if (index < 0 || index > m_size) return;

    if (index == 0)
        push_front(data);
    else {
        Node<T>* current = this->head;

        for (size_t i = 0; i < index - 1; ++i) current = current->next;

        Node<T>* newNode = new Node<T>(data);
        newNode->next    = current->next;
        current->next    = newNode;
        ++m_size;
    }
}

template <typename T>
void LinkedList<T>::remove(const size_t& index) {
    if (index < 0 || index >= m_size) return;

    if (index == 0)
        pop_front();
    else {
        Node<T>* current = this->head;
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
    while (this->head != nullptr) pop_front();
}

template <typename T>
T LinkedList<T>::operator[](const size_t& index) const {
    return get(index);
}

template <typename T>
T& LinkedList<T>::operator[](const size_t& index) {
    if (index < 0 || index >= m_size) return T();

    Node<T>* current = this->head;
    for (int i = 0; i < index; ++i) current = current->next;

    return current->data;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list) {
    Node<T>* current = list.head;
    out << "head -> ";
    while (current != nullptr) {
        out << current->data << " -> ";
        current = current->next;
    }
    out << "tail";
    return out;
}