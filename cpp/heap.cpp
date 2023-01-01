#include "heap.hpp"

#include <iostream>

template <typename T>
int Heap<T>::size() {
    return heap.size();
}

template <typename T>
void Heap<T>::Insert(T element) {
    heap.push_back(element);
    heapifyup(heap.size() - 1);
}

template <typename T>
void Heap<T>::DeleteMin() {
    if (heap.size() == 0)
        std::cout << "Heap is Empty" << std::endl;
    else {
        heap[0] = heap.at(heap.size() - 1);
        heap.pop_back();
        heapifydown(0);
        std::cout << "Element Deleted" << std::endl;
    }
}

template <typename T>
T Heap<T>::ExtractMin() {
    if (heap.size() == 0) return -1;
    return heap.front();
}

template <typename T>
void Heap<T>::DisplayHeap() {
    auto pos = heap.begin();
    while (pos != heap.end()) std::cout << *(pos++) << " ";
    std::cout << std::endl;
}

template <typename T>
int Heap<T>::left(int parent) {
    int l = (parent << 1) + 1;
    if (l < heap.size()) return l;
    return -1;
}

template <typename T>
int Heap<T>::right(int parent) {
    int r = (parent << 1) + 2;
    if (r < heap.size()) return r;
    return -1;
}

template <typename T>
int Heap<T>::parent(int child) {
    int p = (child - 1) >> 1;
    if (child == 0) return -1;
    return p;
}

template <typename T>
void Heap<T>::heapifyup(int index) {
    int parent_index = parent(index);
    if (index >= 0 && parent_index >= 0 && heap[parent_index] > heap[index]) {
        int temp           = heap[index];
        heap[index]        = heap[parent_index];
        heap[parent_index] = temp;
        heapifyup(parent_index);
    }
}

template <typename T>
void Heap<T>::heapifydown(int index) {
    int left_child = left(index), right_child = right(index);
    if (left_child >= 0 && right_child >= 0 &&
        heap[left_child] > heap[right_child]) {
        left_child = right_child;
    }
    if (left_child > 0) {
        int temp         = heap[index];
        heap[index]      = heap[left_child];
        heap[left_child] = temp;
        heapifydown(left_child);
    }
}

int main() {
    Heap<int> h;

    for (int i : {9, 5, 3, 5, 7, 8, 6, 2, 4}) {
        h.Insert(i);
    }

    h.DisplayHeap();

    return 0;
}