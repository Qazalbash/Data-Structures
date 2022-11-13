#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
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
		if (head != nullptr)
		{
			Node<T> *temp = head;
			if (head->value == value)
			{
				head = head->next;
				temp = nullptr;
				delete temp;
			}
			else
			{
				while (temp->next != nullptr)
				{
					if (temp->next->value == value)
					{
						Node<T> *temp2 = temp->next;
						temp->next = temp->next->next;
						delete temp2;
						break;
					}
					temp = temp->next;
				}
			}
		}
	}

	void print()
	{
		if (head == nullptr)
			std::cout << "List is empty" << std::endl;
		else
		{
			Node<T> *current = head;
			while (current != nullptr)
			{
				std::cout << current->value << " ";
				current = current->next;
			}
			std::cout << std::endl;
		}
	}

private:
	Node<T> *head;
};

#endif // LINKED_LIST