template <typename T>
struct Node
{
public:
	Node(T value, Node<T> *next = nullptr) : value(value), next(next) {}
	~Node() { delete next; }

	T value;
	Node<T> *next;
};
