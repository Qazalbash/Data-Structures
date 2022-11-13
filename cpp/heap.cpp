#ifndef HEAP
#define HEAP

#include <iostream>

/**
 * @brief Heap - class Heap
 *
 * @tparam T - Type of the value to be stored in the heap
 */
template <typename T>
class Heap
{
public:
	T value;				  // Value to be stored in the heap
	Heap<T> *left = nullptr;  // Pointer to the left heap
	Heap<T> *right = nullptr; // Pointer to the right heap

	/**
	 * @brief Construct a new Heap object
	 *
	 */
	Heap() : value(0) {}

	/**
	 * @brief Construct a new Heap object
	 *
	 * @param V - Value to be stored in the heap
	 */
	Heap(T V) : value(V) {}

	/**
	 * @brief Construct a new Heap object
	 *
	 * @param V - Value to be stored in the heap
	 * @param L - Pointer to the left heap
	 * @param R - Pointer to the right heap
	 */
	Heap(T V, Heap<T> *L, Heap<T> *R) : value(V), left(L), right(R) {}

	/**
	 * @brief Destroy the Heap object
	 *
	 */
	~Heap()
	{
		if (left != nullptr)
			delete left;
		if (right != nullptr)
			delete right;
	}

	/**
	 * @brief Print the heap
	 *
	 */
	void print()
	{
		cutePrint("", this, false);
	}

	/**
	 * @brief Insert a new value in the heap
	 *
	 * @param V - Value to be inserted
	 */
	void insert(T V)
	{
		insert(this, V);
	}

	// some bugs in merge
	void merge(Heap<T> *H)
	{
		if (value < H->value)
		{
			Heap<T> *temp = H;
			H = this;
			this = temp;
		}
		if (left == nullptr)
			left = H;
		else if (right == nullptr)
			right = H;
		else if (left->value <= right->value)
			left->merge(H);
		else
			right->merge(H);
	}

private:
	// https://stackoverflow.com/a/51730733/14699637
	void cutePrint(const std::string &prefix, const Heap<T> *heap, bool isLeft)
	{
		if (heap != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──");

			// print the value of the node
			std::cout << heap->value << std::endl;

			// enter the next tree level - left and right branch
			cutePrint(prefix + (isLeft ? "│   " : "    "), heap->left, true);
			cutePrint(prefix + (isLeft ? "│   " : "    "), heap->right, false);
		}
	}

	/**
	 * @brief Insert a new value in the heap
	 *
	 * @param V - Value to be inserted
	 */
	void insert(Heap<T> *heap, T V)
	{
		if (heap == nullptr)
			heap = new Heap<T>(V);
		else if (V < heap->value)
		{
			T temp = heap->value;
			heap->value = V;
			V = temp;
		}

		if (heap->left == nullptr)
			heap->left = new Heap<T>(V);
		else if (heap->right == nullptr)
			heap->right = new Heap<T>(V);
		else
		{
			if (heap->left->value > heap->right->value)
				insert(heap->right, V);
			else
				insert(heap->left, V);
		}
	}
};

int main()
{
	Heap<int> h1(7);
	h1.insert(1);
	h1.insert(2);
	h1.insert(3);

	Heap<int> h2(8);
	h2.insert(10);
	h2.insert(9);
	h2.insert(6);

	h1.print();
	h2.print();

	h1.merge(&h2);

	h1.print();

	return 0;
}

#endif // HEAP
