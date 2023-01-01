#include "stack.hpp"

#include <cassert>
#include <iostream>

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);  // append copy of passed elem
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back();  // remove last element
}

template <typename T>
T Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back();  // return copy of last element
}

template <typename T>
bool Stack<T>::empty() const {
    return elems.empty();
}

template <typename T>
Stack<T>::Stack(Stack<T> const& other) {
    elems = other.elems;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> const& other) {
    if (this != &other) elems = other.elems;
    return *this;
}

// #define TEST 0

// #if TEST

// int main() {
//     Stack<int> stack = Stack<int>();
//     stack.push(1);
//     stack.push(2);
//     stack.push(3);

//     std::cout << stack.top() << std::endl;
//     stack.pop();
//     std::cout << stack.top() << std::endl;
//     stack.pop();
//     std::cout << stack.top() << std::endl;
//     stack.pop();

//     return 0;
// }

// #endif