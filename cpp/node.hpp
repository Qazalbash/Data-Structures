#ifndef NODE
#define NODE

template <typename T>
struct Node {
    T        data;
    Node<T>* next;

    /**
     * @brief Construct a new Node object
     *
     * @param data
     */
    Node(const T& data);

    /**
     * @brief Construct a new Node object
     *
     * @param data
     * @param next
     */
    Node(const T& data, const Node<T>* next);
};

#endif  // NODE
