#ifndef STACK
#define STACK

#include <iostream>

#include "node.cpp"

/**
 * @brief Stack - Stack class
 * @param value - Value to be stored in the node
 * @param next - Pointer to the next node
 * @param top - Pointer to the top of the stack
 *
 * @tparam T - Type of the value to be stored in the stack
 */
template <typename T>
class Stack
{
public:
	/**
	 * @brief Construct a new Stack object
	 *
	 */
	Stack() : top(nullptr) {}

	/**
	 * @brief Destroy the Stack object
	 *
	 */
	~Stack() { delete top; }

	/**
	 * @brief Push - Pushes a value to the top of the stack
	 *
	 * @param value - Value to be pushed to the stack
	 */
	void push(const T value)
	{
		Node<T> *newNode = new Node<T>(value, top);
		top = newNode;
	}

	/**
	 * @brief Pop - Pops the top value from the stack
	 *
	 * @return T - Value popped from the stack

	 */
	T pop()
	{
		if (top == nullptr)
			throw "Stack is empty";

		T value = top->getValue();
		Node<T> *temp = top;
		top = top->getNext();
		temp->setNext(nullptr);
		delete temp;
		return value;
	}

	/**
	 * @brief Print - Prints the stack
	 *
	 */
	void print()
	{
		Node<T> *temp = top;
		while (temp != nullptr)
		{
			std::cout << temp->getValue() << ", ";
			temp = temp->getNext();
		}
		std::cout << std::endl;
		delete temp;
	}

private:
	Node<T> *top; // Pointer to the top of the stack
};

#endif // STACK