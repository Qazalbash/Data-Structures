#include "stack.hpp"

#include <cassert>
#include <iostream>

template <typename T>
void Stack<T>::push(T const& elem) {
    this->elems.push_back(elem);  // append copy of passed elem
}

template <typename T>
void Stack<T>::pop() {
    assert(!this->elems.empty());
    this->elems.pop_back();  // remove last element
}

template <typename T>
T Stack<T>::top() const {
    assert(!this->elems.empty());
    return this->elems.back();  // return copy of last element
}

template <typename T>
bool Stack<T>::empty() const {
    return this->elems.empty();
}

template <typename T>
Stack<T>::Stack(Stack<T> const& other) {
    this->elems = other.elems;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> const& other) {
    if (this != &other) this->elems = other.elems;
    return *this;
}