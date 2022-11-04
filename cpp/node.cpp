template <typename T>
class Node
{
public:
	Node(T value, Node<T> *next = nullptr) : value(value), next(next) {}

	T value;
	Node<T> *next;
};
