#include "node.cpp"

template <typename T>
class Stack
{
public:
	Stack() : top(nullptr) {}
	~Stack() { delete top; }

	void push(T value)
	{
		top = new Node<T>(value, top);
	}

	T pop()
	{
		if (top == nullptr)
			throw "Stack is empty";

		T value = top->value;
		Node<T> *temp = top;
		top = top->next;
		delete temp;
		return value;
	}

private:
	Node<T> *top;
};