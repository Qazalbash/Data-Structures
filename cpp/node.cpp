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
	 * @brief Construct a new Node object
	 *
	 * @param N
	 */
	Node(const Node<T> &N) : value(N.value), next(N.next) {}

	/**
	 * @brief Destroy the Node object
	 *
	 */
	~Node()
	{
		delete next;
	}

	/**
	 * @brief Get the Value object
	 *
	 * @return T - Value stored in the node
	 */
	T getValue() const { return value; }

	/**
	 * @brief Set the Value object
	 *
	 * @param V - Value to be stored in the node
	 */
	void setValue(T V) { value = V; }

	/**
	 * @brief Get the Next object
	 *
	 * @return Node<T>* - Pointer to the next node
	 */
	Node<T> *getNext() const { return next; }

	/**
	 * @brief Set the Next object
	 *
	 * @param N - Pointer to the next node
	 */
	void setNext(Node<T> *N) { next = N; }

private:
	T value;				 // Value to be stored in the node
	Node<T> *next = nullptr; // Pointer to the next node
};

#endif // NODE