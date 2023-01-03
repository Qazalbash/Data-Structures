template <typename T>
Node<T>::Node(const T &value) : value(value), left(nullptr), right(nullptr) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

template <typename T>
void BinarySearchTree<T>::insert(const T &value) {
    this->root = this->insert(this->root, value);
}

template <typename T>
void BinarySearchTree<T>::remove(const T &value) {
    this->root = this->remove(this->root, value);
}

template <typename T>
bool BinarySearchTree<T>::contains(const T &value) const {
    return this->contains(this->root, value);
}

template <typename T>
Node<T> *BinarySearchTree<T>::insert(Node<T> *node, const T &value) {
    if (node == nullptr) return new Node<T>(value);

    if (value < node->value)
        node->left = this->insert(node->left, value);
    else if (value > node->value)
        node->right = this->insert(node->right, value);

    return node;
}

template <typename T>
Node<T> *BinarySearchTree<T>::remove(Node<T> *node, const T &value) {
    if (node == nullptr) return nullptr;

    if (value < node->value)
        node->left = this->remove(node->left, value);
    else if (value > node->value)
        node->right = this->remove(node->right, value);
    else {
        if (node->left == nullptr) {
            Node<T> *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T> *temp = node->left;
            delete node;
            return temp;
        }

        Node<T> *temp = this->min(node->right);
        node->value   = temp->value;
        node->right   = this->remove(node->right, temp->value);
    }

    return node;
}

template <typename T>
bool BinarySearchTree<T>::contains(const Node<T> *node, const T &value) const {
    while (node != nullptr) {
        if (value < node->value)
            node = node->left;
        else if (value > node->value)
            node = node->right;
        else
            return true;
    }
    return false;
}

template <typename T>
Node<T> *BinarySearchTree<T>::min(Node<T> *const node) const {
    Node<T> *current = node;

    while (current->left != nullptr) current = current->left;

    return current;
}

template <typename T>
void BinarySearchTree<T>::inorder() const {
    this->inorder(this->root);
}

template <typename T>
void BinarySearchTree<T>::inorder(Node<T> *node) const {
    if (node == nullptr) return;

    this->inorder(node->left);
    std::cout << node->value << " ";
    this->inorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::preorder() const {
    this->preorder(this->root);
}

template <typename T>
void BinarySearchTree<T>::preorder(Node<T> *node) const {
    if (node == nullptr) return;

    std::cout << node->value << " ";
    this->preorder(node->left);
    this->preorder(node->right);
}

template <typename T>
void BinarySearchTree<T>::postorder() const {
    this->postorder(this->root);
}

template <typename T>
void BinarySearchTree<T>::postorder(Node<T> *node) const {
    if (node == nullptr) return;

    this->postorder(node->left);
    this->postorder(node->right);
    std::cout << node->value << " ";
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Node<T> &node) {
    os << node.data;
    return os;
}

template <typename T>
void print(const std::string &prefix, const Node<T> *node, bool is_left) {
    if (node != nullptr) {
        std::cout << prefix << (is_left ? "├──" : "└──") << node->value
                  << std::endl;

        print(prefix + (is_left ? "│   " : "    "), node->left, true);
        print(prefix + (is_left ? "│   " : "    "), node->right, false);
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const BinarySearchTree<T> &bst) {
    print("", bst.root, false);
    return os;
}