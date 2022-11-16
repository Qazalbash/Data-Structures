#ifndef QUEUE
#define QUEUE

#include <iostream>
#include "node.cpp"

/**
 * @brief Queue - Queue class
 * @param front - Pointer to the front of the queue
 * @param back - Pointer to the back of the queue
 *
 * @tparam T - Type of the value to be stored in the queue
 */
template <typename T>
class Queue
{
public:
	/**
	 * @brief Construct a new Queue object
	 *
	 */
	Queue() : front(nullptr), back(nullptr) {}

	/**
	 * @brief Destroy the Queue object
	 *
	 */
	~Queue()
	{
		delete front;
		delete back;
	}

	/**
	 * @brief Enqueue - Enqueues a value to the back of the queue
	 *
	 * @param value - Value to be enqueued to the queue
	 */
	void enqueue(const T value)
	{
		Node<T> *newNode = new Node<T>(value);
		if (front == nullptr)
			front = newNode;
		else
			back->setNext(newNode);
		back = newNode;
	}

	/**
	 * @brief Dequeue - Dequeues the front value from the queue
	 *
	 * @return T - Value dequeued from the queue
	 */
	T dequeue()
	{
		if (front == nullptr)
			throw std::runtime_error("Queue is empty");

		T value = front->getValue();
		Node<T> *temp = front;
		front = front->getNext();
		temp->setNext(nullptr);
		if (front == back)
			delete temp;
		return value;
	}

	/**
	 * @brief Print - Prints the queue
	 *
	 */
	void print()
	{
		if (front == nullptr)
		{
			std::cout << "Queue is empty" << std::endl;
		}
		else
		{
			Node<T> *temp = front;
			while (temp != nullptr)
			{
				std::cout << temp->getValue() << " ";
				temp = temp->getNext();
			}
			std::cout << std::endl;
			delete temp;
		}
	}

private:
	Node<T> *front; // Pointer to the front of the queue
	Node<T> *back;	// Pointer to the back of the queue
};

#endif // QUEUE