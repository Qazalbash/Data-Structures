#ifndef NODE
#define NODE

/**
 * @brief Node - class Node
 * @param value - Value to be stored in the node
 * @param next - Pointer to the next node
 *
 * @tparam T - Type of the value to be stored in the stack
 */
template <typename T>
class Node
{
public:
	/**
	 * @brief Construct a new Node object
	 *
	 * @param V - Value to be stored in the node
	 */
	Node(T V) : value(V) {}

	/**
	 * @brief Construct a new Node object
	 *
	 * @param V - Value to be stored in the node
	 * @param N - Pointer to the next node
	 */
	Node(T V, Node<T> *N) : value(V), next(N) {}

	/**
	 * @brief Destroy the Node object
	 *
	 */
	~Node()
	{
		if (next->next != nullptr)
			delete next;
	}

	T value;				 // Value to be stored in the node
	Node<T> *next = nullptr; // Pointer to the next node
};

#endif // NODE