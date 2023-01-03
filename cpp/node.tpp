template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr) {}

template <typename T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next) {}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    out << node.data;
    return out;
}