#include "node.cpp"

template <typename T>
class Heap
{
public:
	Heap() : root(nullptr) {}
	~Heap() { delete root; }

	void insert(const T value) { root = insert(root, value); }
	void remove(const T value) { root = remove(root, value); }
	Heap *merge(Heap *heap1, Heap *heap2) { return merge(heap1->root, heap2->root); }

private:
	Node<T> *root;

	Node<T> *insert(Node<T> *node, const T value)
	{
		if (node == nullptr)
			return new Node<T>(value);

		if (value < node->value)
			node->left = insert(node->left, value);
		else if (value > node->value)
			node->right = insert(node->right, value);

		return node;
	}

	Node<T> *remove(Node<T> *node, const T value)
	{
		if (node == nullptr)
			return nullptr;

		if (value < node->value)
			node->left = remove(node->left, value);
		else if (value > node->value)
			node->right = remove(node->right, value);
		else
		{
			if (node->left == nullptr)
			{
				Node<T> *temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				Node<T> *temp = node->left;
				delete node;
				return temp;
			}

			Node<T> *temp = min(node->right);
			node->value = temp->value;
			node->right = remove(node->right, temp->value);
		}

		return node;
	}

	Node<T> *merge(Node<T> *node1, Node<T> *node2)
	{
		if (node1 == nullptr)
			return node2;
		if (node2 == nullptr)
			return node1;

		if (node1->value < node2->value)
			return merge(node1, node2);
		else
			return merge(node2, node1);
	}
};
