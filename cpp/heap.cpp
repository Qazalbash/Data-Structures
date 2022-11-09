#include <iostream>

template <typename T>
struct Node
{
	Node(T V, Node<T> *L = nullptr, Node<T> *R = nullptr) : value(V), left(L), right(R) {}
	~Node()
	{
		delete left;
		delete right;
	}

	T value;
	Node<T> *left, *right;
};

template <typename T>
class Heap
{
public:
	Heap() : root(nullptr) {}
	~Heap() { delete root; }

	void insert(const T value) { insert(root, value); }
	void remove(const T value) { remove(root, value); }
	Heap *merge(Heap *heap1, Heap *heap2) { return merge(heap1->root, heap2->root); }
	void print() { print(root); }

private:
	Node<T> *root;

	void insert(Node<T> *node, T value)
	{
		if (node == nullptr)
		{
			node = new Node<T>(value);
			return;
		}

		if (value < node->value)
		{
			T temp = node->value;
			node->value = value;
			value = temp;
		}

		if (node->left == nullptr)
			node->left = new Node<T>(value);
		else if (node->right == nullptr)
			node->right = new Node<T>(value);
		else if (node->left->value < node->right->value)
			insert(node->left, value);
		else
			insert(node->right, value);
	}

	void remove(Node<T> *node, const T value)
	{
		if (node == nullptr)
			return;

		if (node->value == value)
		{
			Heap *heap = merge(node->left, node->right);
			node->value = heap->root->value;
			node->left = heap->root->left;
			node->right = heap->root->right;
			delete heap;
		}
		else
		{
			remove(node->left, value);
			remove(node->right, value);
		}
	}

	Node<T> *merge(Node<T> *node1, Node<T> *node2)
	{
		if (node1 == nullptr)
			return node2;
		if (node2 == nullptr)
			return node1;

		if (node1->value < node2->value)
		{
			node1->right = merge(node1->right, node2);
			return node1;
		}
		else
		{
			node2->right = merge(node1, node2->right);
			return node2;
		}
	}

	void print(Node<T> *node)
	{
		if (node != nullptr)
		{
			print(node->left);
			std::cout << node->value << " ";
			print(node->right);
		}
	}
};

int main()
{
	Heap<int> heap;
	heap.insert(3);
	heap.insert(2);
	heap.insert(15);
	heap.insert(5);
	heap.insert(4);
	heap.insert(45);

	// heap.print();

	return 0;
}