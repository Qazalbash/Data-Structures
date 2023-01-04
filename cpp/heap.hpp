#ifndef HEAP
#define HEAP

#include <ostream>
#include <vector>

typedef unsigned long size_t;

template <typename T>
class Heap {
public:

    Heap() = default;

    void insert(const T&);

    void delete_min();
    T    extract_min() const;

    size_t size() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Heap<U>&);

private:

    std::vector<T> m_heap;

    int left(int) const;
    int right(int) const;
    int parent(int) const;

    void heapifyup(const int&);
    void heapifydown(const int&);
};

#include "heap.tpp"

#endif  // HEAP