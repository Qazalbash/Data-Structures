#ifndef NODE
#define NODE

#include <ostream>

template <typename T>
struct Node {
public:

    T        data;
    Node<T>* next;

    Node(const T&);
    Node(const T&, Node<T>*);

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Node<U>&);
};

#include "node.tpp"

#endif  // NODE
