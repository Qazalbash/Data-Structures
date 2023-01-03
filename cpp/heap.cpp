#include "heap.hpp"

#include <iostream>

template <typename T>
size_t Heap<T>::size() const {
    return this->heap.size();
}

template <typename T>
void Heap<T>::Insert(const T& element) {
    this->heap.push_back(element);
    this->heapifyup(this->heap.size() - 1);
}

template <typename T>
void Heap<T>::DeleteMin() {
    if (this->heap.size() == 0)
        std::cout << "Heap is Empty" << std::endl;
    else {
        this->heap[0] = this->heap.at(this->heap.size() - 1);
        this->heap.pop_back();
        this->heapifydown(0);
        std::cout << "Element Deleted" << std::endl;
    }
}

template <typename T>
T Heap<T>::ExtractMin() const {
    if (this->heap.size() == 0) return -1;
    return this->heap.front();
}

template <typename T>
void Heap<T>::DisplayHeap() const {
    auto pos = this->heap.begin();
    while (pos != this->heap.end()) std::cout << *(pos++) << " ";
    std::cout << std::endl;
}

template <typename T>
int Heap<T>::left(int parent) const {
    const int l = (parent << 1) + 1;
    if (l < this->heap.size()) return l;
    return -1;
}

template <typename T>
int Heap<T>::right(int parent) const {
    const int r = (parent << 1) + 2;
    if (r < this->heap.size()) return r;
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
        this->heap[parent_index] > this->heap[index]) {
        int temp                 = this->heap[index];
        this->heap[index]        = this->heap[parent_index];
        this->heap[parent_index] = temp;
        this->heapifyup(parent_index);
    }
}

template <typename T>
void Heap<T>::heapifydown(const int& index) {
    int left_child = this->left(index), right_child = this->right(index);
    if (left_child >= 0 && right_child >= 0 &&
        this->heap[left_child] > this->heap[right_child]) {
        left_child = right_child;
    }
    if (left_child > 0) {
        int temp               = this->heap[index];
        this->heap[index]      = this->heap[left_child];
        this->heap[left_child] = temp;
        this->heapifydown(left_child);
    }
}