template <typename T>
size_t Heap<T>::size() const {
    return this->m_heap.size();
}

template <typename T>
void Heap<T>::insert(const T& element) {
    this->m_heap.push_back(element);
    this->heapifyup(this->m_heap.size() - 1);
}

template <typename T>
void Heap<T>::delete_min() {
    if (this->m_heap.size() == 0) return;
    this->m_heap[0] = this->m_heap.at(this->m_heap.size() - 1);
    this->m_heap.pop_back();
    this->heapifydown(0);
}

template <typename T>
T Heap<T>::extract_min() const {
    if (this->m_heap.size() == 0) return -1;
    return this->m_heap.front();
}

template <typename T>
int Heap<T>::left(int parent) const {
    const int l = (parent << 1) + 1;
    if (l < this->m_heap.size()) return l;
    return -1;
}

template <typename T>
int Heap<T>::right(int parent) const {
    const int r = (parent << 1) + 2;
    if (r < this->m_heap.size()) return r;
    return -1;
}

template <typename T>
int Heap<T>::parent(int child) const {
    if (child == 0) return -1;
    const int p = (child - 1) >> 1;
    return p;
}

template <typename T>
void Heap<T>::heapifyup(const int& index) {
    const int parent_index = this->parent(index);
    if (index >= 0 && parent_index >= 0 &&
        this->m_heap[parent_index] > this->m_heap[index]) {
        int temp                   = this->m_heap[index];
        this->m_heap[index]        = this->m_heap[parent_index];
        this->m_heap[parent_index] = temp;
        this->heapifyup(parent_index);
    }
}

template <typename T>
void Heap<T>::heapifydown(const int& index) {
    int left_child = this->left(index), right_child = this->right(index);
    if (left_child >= 0 && right_child >= 0 &&
        this->m_heap[left_child] > this->m_heap[right_child]) {
        left_child = right_child;
    }
    if (left_child > 0) {
        int temp                 = this->m_heap[index];
        this->m_heap[index]      = this->m_heap[left_child];
        this->m_heap[left_child] = temp;
        this->heapifydown(left_child);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Heap<T>& m_heap) {
    auto head = m_heap.m_heap.begin(), tail = m_heap.m_heap.end() - 1;
    out << "[";
    while (head != tail) out << *(head++) << ", ";
    out << *head << "]";
    return out;
}