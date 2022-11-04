#include "node.cpp"

template <typename T>
class Queue
{
public:
	Queue() : head(nullptr), tail(nullptr) {}
	~Queue()
	{
		delete head;
		delete tail;
	}

	void enqueue(const T value)
	{
		if (head == nullptr)
		{
			head = new Node<T>(value);
			tail = head;
		}
		else
		{
			tail->next = new Node<T>(value);
			tail = tail->next;
		}
	}

	T dequeue()
	{
		if (head == nullptr)
			throw "Queue is empty";

		T value = head->value;
		Node<T> *temp = head;
		head = head->next;
		delete temp;
		return value;
	}

private:
	Node<T> *head, *tail;
};