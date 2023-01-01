#ifndef STACK
#define STACK

#include <vector>

template <typename T>
class Stack {
private:

    std::vector<T> elems;  // elements

public:

    /**
     * @brief Push element
     *
     */
    void push(T const&);

    /**
     * @brief Pop element
     *
     */
    void pop();

    /**
     * @brief Return top element
     *
     * @return T
     */
    T top() const;

    /**
     * @brief Check if stack is empty
     *
     * @return true
     * @return false
     */
    bool empty() const;

    /**
     * @brief Construct a new Stack object
     *
     */
    Stack() = default;

    /**
     * @brief Construct a new Stack object
     *
     * @param other
     */
    Stack(Stack<T> const& other);

    /**
     * @brief Assign operator
     *
     * @param other
     * @return Stack<T>&
     */
    Stack<T>& operator=(Stack<T> const& other);
};

#endif  // STACK