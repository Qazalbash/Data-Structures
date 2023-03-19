template <typename T>
graph::AVLTree<T>::AVLTree() : BinarySearchTree<T>() {}

template <typename T>
graph::AVLTree<T>::AVLTree(const AVLTree<T> &avl_tree) : BinarySearchTree<T>(avl_tree) {}

template <typename T>
graph::AVLTree<T>::~AVLTree() {}

template <typename T>
void graph::AVLTree<T>::insert(const T &value) {
    BinarySearchTree<T>::insert(value);
    this->m_root = this->balance(this->m_root);
}

template <typename T>
void graph::AVLTree<T>::remove(const T &value) {
    BinarySearchTree<T>::remove(value);
    this->m_root = this->balance(this->m_root);
}

template <typename T>
bool graph::AVLTree<T>::contains(const T &value) const {
    return BinarySearchTree<T>::contains(value);
}

template <typename T>
void graph::AVLTree<T>::inorder() const {
    BinarySearchTree<T>::inorder();
}

template <typename T>
void graph::AVLTree<T>::preorder() const {
    BinarySearchTree<T>::preorder();
}

template <typename T>
void graph::AVLTree<T>::postorder() const {
    BinarySearchTree<T>::postorder();
}

template <typename T>
int graph::AVLTree<T>::height(const binary::Node<T> *node) const {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

template <typename T>
int graph::AVLTree<T>::balance_factor(binary::Node<T> *node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

template <typename T>
binary::Node<T> *graph::AVLTree<T>::left_child(binary::Node<T> *node) const {
    return node->left;
}

template <typename T>
binary::Node<T> *graph::AVLTree<T>::right_child(binary::Node<T> *node) const {
    return node->right;
}

template <typename T>
binary::Node<T> *graph::AVLTree<T>::rotate_left(binary::Node<T> *node) {
    binary::Node<T> *new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;

    return new_root;
}

template <typename T>
binary::Node<T> *graph::AVLTree<T>::rotate_right(binary::Node<T> *node) {
    binary::Node<T> *new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;

    return new_root;
}

template <typename T>
binary::Node<T> *graph::AVLTree<T>::balance(binary::Node<T> *node) {
    if (node == nullptr) {
        return node;
    }

    node->height = std::max(height(node->left), height(node->right)) + 1;

    int bf = balance_factor(node);

    if (bf > 1) {
        if (balance_factor(node->left) < 0) {
            node->left = rotate_left(node->left);
        }
        return rotate_right(node);
    } else if (bf < -1) {
        if (balance_factor(node->right) > 0) {
            node->right = rotate_right(node->right);
        }
        return rotate_left(node);
    }

    return node;
}

template <typename T>
binary::Node<T> *graph::AVLTree<T>::insert(binary::Node<T> *node, const T &value) {
    if (node == nullptr) {
        return new binary::Node<T>(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    return node;
}

template <typename T>
binary::Node<T> *graph::AVLTree<T>::remove(binary::Node<T> *node, const T &value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr) {
            binary::Node<T> *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            binary::Node<T> *temp = node->left;
            delete node;
            return temp;
        }

        binary::Node<T> *temp = min_value_node(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
    }

    return node;
}

template <typename T>
std::ostream &graph::operator<<(std::ostream &os, const graph::AVLTree<T> &avltree) {
    print("", avltree.m_root, false);
    return os;
}