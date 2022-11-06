#include "node.cpp"

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree() : root(nullptr) {}
	~BinarySearchTree() { delete root; }

	void insert(T value) { root = insert(root, value); }
	void remove(T value) { root = remove(root, value); }
	bool contains(T value) { return contains(root, value); }

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

	bool contains(Node<T> *node, T value)
	{
		if (node == nullptr)
			return false;

		if (value < node->value)
			return contains(node->left, value);
		else if (value > node->value)
			return contains(node->right, value);
		else
			return true;
	}

	Node<T> *min(Node<T> *node)
	{
		Node<T> *current = node;

		while (current->left != nullptr)
			current = current->left;

		return current;
	}
};