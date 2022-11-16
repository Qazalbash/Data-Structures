#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include "node.cpp"

/**
 * @brief LinkedList - class LinkedList
 *
 * @tparam T - Type of the value to be stored in the stack
 */
template <typename T>
class LinkedList
{
public:
	/**
	 * @brief Construct a new Linked List object
	 *
	 */
	LinkedList() : head(nullptr) {}

	/**
	 * @brief Construct a new Linked List object
	 *
	 * @param L - LinkedList to be copied
	 */
	LinkedList(const LinkedList<T> &L) : head(L.head) {}

	/**
	 * @brief Destroy the Linked List object
	 *
	 */
	~LinkedList() { delete head; }

	/**
	 * @brief Get the Head object
	 *
	 * @return Node<T>* - Pointer to the head of the list
	 */
	Node<T> *getHead() const { return head; }

	/**
	 * @brief Set the Head object
	 *
	 * @param H - Pointer to the head of the list
	 */
	void setHead(Node<T> *H) { head = H; }

	/**
	 * @brief Get the Tail object
	 *
	 * @return Node<T>* - Pointer to the tail of the list
	 */
	Node<T> *getTail() const
	{
		Node<T> *tail = head;
		while (tail->getNext() != nullptr)
			tail = tail->getNext();
		return tail;
	}

	/**
	 * @brief Get the Size object
	 *
	 * @return int - Size of the list
	 */
	unsigned int getSize() const
	{
		unsigned int size = 0;
		Node<T> current = *head;
		while (current != nullptr)
		{
			size++;
			current = *(current.getNext());
		}
		return size;
	}

	/**
	 * @brief Get the Value object
	 *
	 * @param index - Index of the value to be returned
	 * @return T - Value stored in the node at the given index
	 */
	T getValue(int index) const
	{
		Node<T> current = *head;
		for (int i = 0; i < index; i++)
			current = *(current.getNext());
		return current.getValue();
	}

	/**
	 * @brief Set the Value object
	 *
	 * @param index - Index of the value to be set
	 * @param V - Value to be stored in the node at the given index
	 */
	void setValue(int index, T V)
	{
		Node<T> current = *head;
		for (int i = 0; i < index; i++)
			current = *(current.getNext());
		current.setValue(V);
	}

	/**
	 * @brief Insert a new node at the given index
	 *
	 * @param index - Index at which the new node is to be inserted
	 * @param V - Value to be stored in the new node
	 */
	void insert(int index, T V)
	{
		if (index == 0)
			head = new Node<T>(V, head);
		else
		{
			Node<T> *current = head;
			for (int i = 0; i < index - 1; i++)
				current = current->getNext();
			current->setNext(new Node<T>(V, current->getNext()));
		}
	}

	/**
	 * @brief Insert a new node at the end of the list
	 *
	 * @param value
	 */
	void insert(const T value)
	{
		if (head == nullptr)
			head = new Node<T>(value);
		else
		{
			Node<T> *temp = head;
			while (temp->getNext() != nullptr)
				temp = temp->getNext();
			temp->setNext(new Node<T>(value));
		}
	}

	/**
	 * @brief Remove the node at the given index
	 *
	 * @param index - Index of the node to be removed
	 */
	void remove(const int index)
	{
		Node<T> *temp = head;
		if (index == 0)
		{
			head = head->getNext();
		}
		else
		{
			Node<T> *current = head;
			for (int i = 0; i < index - 1; i++)
				current = current->getNext();
			temp = current->getNext();
			current->setNext(temp->getNext());
		}
		temp->setNext(nullptr);
		delete temp;
	}

	/**
	 * @brief Print the list
	 *
	 */
	void print() const
	{
		Node<T> *current = head;
		while (current != nullptr)
		{
			std::cout << current->getValue() << " ";
			current = current->getNext();
		}
		std::cout << std::endl;
		delete current;
	}

private:
	Node<T> *head;
};

int main()
{
	LinkedList<int> L1;
	L1.insert(1);
	L1.insert(2);
	L1.insert(3);

	LinkedList<int> L2;
	L2.insert(13);
	L2.insert(23);
	L2.insert(33);

	L1.print();
	L2.print();
	L1.print();

	return 0;
}

#endif // LINKED_LIST