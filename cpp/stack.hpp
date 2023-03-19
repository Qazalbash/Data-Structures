/**
 * @file stack.hpp
 * @author Meesum Ali Qazalbash (mesumali26.ma@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef STACK
#define STACK

#include <cassert>
#include <ostream>
#include <vector>

/**
 * @brief
 *
 */
namespace linear {
/**
 * @brief
 *
 * @tparam T
 */
template <typename T>
class Stack {
 public:
    /**
     * @brief Construct a new Stack object
     */
    Stack() = default;

    /**
     * @brief Construct a new Stack object
     *
     * @param other
     */
    Stack(Stack<T> const& other);

    /**
     * @brief Push new object
     *
     * @param element
     */
    void push(const T& element);

    /**
     * @brief Pop the top element
     *
     */
    void pop();

    /**
     * @brief Peek the top of the stack
     *
     * @return T
     */
    T top() const;

    /**
     * @brief Check if the stack is empty
     *
     * @return bool
     */
    bool empty() const;

    /**
     * @brief Assignment operator
     *
     * @param other
     * @return Stack<T>&
     */
    Stack<T>& operator=(Stack<T> const& other);

 private:
    std::vector<T> m_stack;  // elements
};

/**
 * @brief
 *
 * @tparam U
 * @return std::ostream&
 */
template <typename U>
std::ostream& operator<<(std::ostream&, const Stack<U>&);

}  // namespace linear

#include "stack.tpp"

#endif  // STACK