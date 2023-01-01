#ifndef NODE
#define NODE

template <typename T>
struct Node {
    T        data;
    Node<T>* next;

    Node(const T& data);
    Node(const T& data, const Node<T>* next);
};

// /**
//  * @brief Node - class Node
//  * @param data - Value to be stored in the node
//  * @param next - Pointer to the next node
//  *
//  * @tparam T - Type of the data to be stored in the stack
//  */
// template <typename T>
// class Node {
// public:

//     /**
//      * @brief Construct a new Node object
//      *
//      * @param V - Value to be stored in the node
//      */
//     Node(T V);

//     /**
//      * @brief Construct a new Node object
//      *
//      * @param V - Value to be stored in the node
//      * @param N - Pointer to the next node
//      */
//     Node(T V, Node<T>* N);

//     /**
//      * @brief Construct a new Node object
//      *
//      * @param N
//      */
//     Node(const Node<T>& N);

//     /**
//      * @brief Destroy the Node object
//      *
//      */
//     ~Node() = default;

//     /**
//      * @brief Get the Value object
//      *
//      * @return T - Value stored in the node
//      */
//     T getValue() const;

//     /**
//      * @brief Set the Value object
//      *
//      * @param V - Value to be stored in the node
//      */
//     void setValue(T V);

//     /**
//      * @brief Get the Next object
//      *
//      * @return Node<T>* - Pointer to the next node
//      */
//     Node<T>* getNext() const;

//     /**
//      * @brief Set the Next object
//      *
//      * @param N - Pointer to the next node
//      */
//     void setNext(Node<T>* N);

//     /**
//      * @brief Operator = - Overload of the assignment operator
//      *
//      * @param other - Node to be copied
//      * @return Node<T>& - Reference to the node
//      */
//     Node<T>& operator=(const Node<T>& other);

//     T        data;            // Value to be stored in the node
//     Node<T>* next = nullptr;  // Pointer to the next node
// };

#endif  // NODE
