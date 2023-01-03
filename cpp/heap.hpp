#ifndef HEAP
#define HEAP

#include <vector>

typedef unsigned long size_t;

/**
 * @brief Heap class
 *
 * @tparam T
 */
template <typename T>
class Heap {
public:

    /**
     * @brief Construct a new Heap object
     *
     */
    Heap() = default;

    /**
     * @brief Insert an element into the heap
     *
     * @param element
     */
    void Insert(const T& element);

    /**
     * @brief Delete the minimum element from the heap
     *
     */
    void DeleteMin();

    /**
     * @brief Extract the minimum element from the heap
     *
     * @return T
     */
    T ExtractMin() const;

    /**
     * @brief Display the heap
     *
     */
    void DisplayHeap() const;

    /**
     * @brief Get the size of the heap
     *
     * @return int
     */
    size_t size() const;

private:

    std::vector<T> heap;

    int left(int parent) const;
    int right(int parent) const;
    int parent(int child) const;

    void heapifyup(const int& index);
    void heapifydown(const int& index);
};

#endif  // HEAP