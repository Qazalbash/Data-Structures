#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.hpp"

typedef unsigned long size_t;

template <typename T>
class LinkedList {
public:

    LinkedList();
    LinkedList(const T&);
    LinkedList(const LinkedList&);

    ~LinkedList();

    void insert(const size_t&, const T&);
    void remove(const size_t&);
    int  size() const;

    bool is_empty() const;
    void clear();

    void push_front(const T&);
    void push_back(const T&);

    LinkedList& operator=(const LinkedList&);
    bool        operator==(const LinkedList&) const;
    bool        operator!=(const LinkedList&) const;
    T           operator[](const size_t&) const;
    T&          operator[](const size_t&);

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<U>&);

private:

    Node<T>* m_head;
    size_t   m_size = 0;
};

#include "linked_list.tpp"

#endif  // LINKED_LIST
