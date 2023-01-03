#ifndef BST
#define BST

template <typename T>
struct Node {
    T        value;
    int      height;
    Node<T> *left, *right;

    Node(const T &value);
};

template <typename T>
class BinarySearchTree {
public:

    /**
     * @brief Construct a new Binary Search Tree object
     *
     */
    BinarySearchTree();

    /**
     * @brief Destroy the Binary Search Tree object
     *
     */
    ~BinarySearchTree();

    /**
     * @brief Insert a new value into the tree
     *
     * @param value
     */
    void insert(const T &value);

    /**
     * @brief Remove a value from the tree
     *
     * @param value
     */
    void remove(const T &value);

    /**
     * @brief Check if the tree contains a value
     *
     * @param value
     * @return true
     * @return false
     */
    bool contains(const T &value) const;

    /**
     * @brief Print the tree in order
     *
     */
    void inorder() const;

    /**
     * @brief Print the tree in preorder
     *
     */
    void preorder() const;

    /**
     * @brief Print the tree in postorder
     *
     */
    void postorder() const;

protected:

    Node<T> *root;

private:

    Node<T> *insert(Node<T> *node, const T &value);
    Node<T> *remove(Node<T> *node, const T &value);
    bool     contains(const Node<T> *node, const T &value) const;

    Node<T> *min(Node<T> *const node) const;

    void inorder(Node<T> *node) const;
    void preorder(Node<T> *node) const;
    void postorder(Node<T> *node) const;
};

#endif  // BST