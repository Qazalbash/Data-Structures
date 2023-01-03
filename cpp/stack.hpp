#ifndef STACK
#define STACK

#include <cassert>
#include <ostream>
#include <vector>

template <typename T>
class Stack {
public:

    Stack() = default;
    Stack(Stack<T> const&);

    void push(const T&);
    void pop();
    T    top() const;
    bool empty() const;

    Stack<T>& operator=(Stack<T> const&);

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const Stack<U>&);

private:

    std::vector<T> m_stack;  // elements
};

#include "stack.tpp"

#endif  // STACK