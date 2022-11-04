#include "node.cpp"

template <typename T>
class LinkedList
{
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() { delete head; }

	void insert(const T value) { head = new Node<T>(value, head); }

	void remove(const T value)
	{
		if (head == nullptr)
			throw "List is empty";

		if (head->value == value)
		{
			Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			Node<T> *current = head;

			while (current->next != nullptr && current->next->value != value)
				current = current->next;

			if (current->next == nullptr)
				throw "Value not found";

			Node<T> *temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
	}

private:
	Node<T> *head;
};