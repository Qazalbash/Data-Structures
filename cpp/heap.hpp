#ifndef HEAP
#define HEAP

#include <vector>

/**
 * @brief
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
     * @brief
     *
     * @param element
     */
    void Insert(T element);

    /**
     * @brief
     *
     */
    void DeleteMin();

    /**
     * @brief
     *
     * @return T
     */
    T ExtractMin();

    /**
     * @brief
     *
     */
    void DisplayHeap();

    /**
     * @brief
     *
     * @return int
     */
    int size();

private:

    std::vector<T> heap;

    int left(int parent);
    int right(int parent);
    int parent(int child);

    void heapifyup(int index);
    void heapifydown(int index);
};

#endif  // HEAP