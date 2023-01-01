#ifndef LINKED_LIST
#define LINKED_LIST

/**
 * @brief Node struct that contains the data and a pointer to the next node
 *
 * @tparam T
 */
template <typename T>
struct Node {
public:

    T        data;
    Node<T>* next;

    Node(const T& data);
    Node(const T& data, const Node<T>* next);
};

template <typename T>
class LinkedList {
private:

    Node<T>* head;
    int      size;

public:

    /**
     * @brief Construct a new Linked List object
     *
     */
    LinkedList();

    /**
     * @brief Construct a new Linked List object with a given element
     *
     * @param data
     */
    LinkedList(const T& data);

    /**
     * @brief Construct a new Linked List object
     *
     * @param other
     */
    LinkedList(const LinkedList& other);

    /**
     * @brief Destroy the Linked List object
     *
     */
    ~LinkedList();

    /**
     * @brief Copy assignment operator
     *
     * @param other
     * @return LinkedList&
     */
    LinkedList& operator=(const LinkedList& other);

    /**
     * @brief Equality operator
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator==(const LinkedList& other) const;

    /**
     * @brief Inequality operator
     *
     * @param other
     * @return true
     * @return false
     */
    bool operator!=(const LinkedList& other) const;

    /**
     * @brief Inserts an element at the front of the linked list
     *
     * @param data
     */
    void push_front(T data);

    /**
     * @brief Inserts an element at the back of the linked list
     *
     * @param data
     */
    void push_back(T data);

    /**
     * @brief Removes the element at the front of the linked list
     *
     */
    void pop_front();

    /**
     * @brief Removes the element at the back of the linked list
     *
     */
    void pop_back();

    /**
     * @brief Returns the element at the front of the linked list
     *
     * @return T
     */
    T front() const;

    /**
     * @brief Returns the element at the back of the linked list
     *
     * @return T
     */
    T back() const;

    /**
     * @brief Returns the element at the given index
     *
     * @param index
     * @return T
     */
    T get(int index) const;

    /**
     * @brief Sets the element at the given index
     *
     * @param index
     * @param data
     */
    void set(int index, T data);

    /**
     * @brief Inserts an element at the given index
     *
     * @param index
     * @param data
     */
    void insert(int index, T data);

    /**
     * @brief Removes the element at the given index
     *
     * @param index
     */
    void remove(int index);

    /**
     * @brief Get the Size object
     *
     * @return int
     */
    int getSize() const;

    /**
     * @brief Checks if the linked list is empty
     *
     * @return true
     * @return false
     */
    bool isEmpty() const;

    /**
     * @brief Clears the linked list
     *
     */
    void clear();

    /**
     * @brief Prints the linked list
     *
     */
    void print() const;

    /**
     * @brief Returns the element at the given index
     *
     * @param index
     * @return T
     */
    T operator[](int index) const;

    /**
     * @brief Returns the element at the given index
     *
     * @param index
     * @return T&
     */
    T& operator[](int index);
};

#endif  // LINKED_LIST
