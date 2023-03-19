template <typename T>
binary::Node<T>::Node(const T &value) : value(value), left(nullptr), right(nullptr) {}

template <typename T>
binary::Node<T>::Node(const binary::Node<T> &node) : value(node.value), left(node.left), right(node.right) {}

template <typename T>
binary::Node<T>::~Node() {
    delete this->left;
    delete this->right;
}

template <typename T>
std::ostream &binary::operator<<(std::ostream &os, const binary::Node<T> &node) {
    os << node.value;
    return os;
}

template <typename T>
graph::BinarySearchTree<T>::BinarySearchTree() : m_root(nullptr) {}

template <typename T>
graph::BinarySearchTree<T>::BinarySearchTree(const graph::BinarySearchTree<T> &bst) : m_root(bst.m_root) {}

template <typename T>
graph::BinarySearchTree<T>::~BinarySearchTree() {
    delete m_root;
}

template <typename T>
void graph::BinarySearchTree<T>::insert(const T &value) {
    this->m_root = this->insert(this->m_root, value);
}

template <typename T>
void graph::BinarySearchTree<T>::remove(const T &value) {
    this->m_root = this->remove(this->m_root, value);
}

template <typename T>
bool graph::BinarySearchTree<T>::contains(const T &value) const {
    return this->contains(this->m_root, value);
}

template <typename T>
binary::Node<T> *graph::BinarySearchTree<T>::insert(binary::Node<T> *node, const T &value) {
    if (node == nullptr) {
        return new binary::Node<T>(value);
    }

    if (value < node->value) {
        node->left = this->insert(node->left, value);
    } else if (value > node->value) {
        node->right = this->insert(node->right, value);
    }

    return node;
}

template <typename T>
binary::Node<T> *graph::BinarySearchTree<T>::remove(binary::Node<T> *node, const T &value) {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->value) {
        node->left = this->remove(node->left, value);
    } else if (value > node->value) {
        node->right = this->remove(node->right, value);
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

        binary::Node<T> *temp = this->min(node->right);
        node->value = temp->value;
        node->right = this->remove(node->right, temp->value);
    }

    return node;
}

template <typename T>
bool graph::BinarySearchTree<T>::contains(const binary::Node<T> *node, const T &value) const {
    while (node != nullptr) {
        if (value < node->value) {
            node = node->left;
        } else if (value > node->value) {
            node = node->right;
        } else {
            return true;
        }
    }
    return false;
}

template <typename T>
binary::Node<T> *graph::BinarySearchTree<T>::min(binary::Node<T> *const node) const {
    binary::Node<T> *current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

template <typename T>
void graph::BinarySearchTree<T>::inorder() const {
    this->inorder(this->m_root);
}

template <typename T>
void graph::BinarySearchTree<T>::inorder(binary::Node<T> *node) const {
    if (node == nullptr) {
        return;
    }

    this->inorder(node->left);
    std::cout << node->value << " ";
    this->inorder(node->right);
}

template <typename T>
void graph::BinarySearchTree<T>::preorder() const {
    this->preorder(this->m_root);
}

template <typename T>
void graph::BinarySearchTree<T>::preorder(binary::Node<T> *node) const {
    if (node == nullptr) {
        return;
    }

    std::cout << node->value << " ";
    this->preorder(node->left);
    this->preorder(node->right);
}

template <typename T>
void graph::BinarySearchTree<T>::postorder() const {
    this->postorder(this->m_root);
}

template <typename T>
void graph::BinarySearchTree<T>::postorder(binary::Node<T> *node) const {
    if (node == nullptr) {
        return;
    }

    this->postorder(node->left);
    this->postorder(node->right);
    std::cout << node->value << " ";
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const binary::Node<T> &node) {
    os << node.data;
    return os;
}

template <typename T>
void print(const std::string &prefix, const binary::Node<T> *const node, bool is_left) {
    if (node == nullptr) {
        return
    }

    std::cout << prefix << (is_left ? "├──" : "└──") << node->value << std::endl;

    print(prefix + (is_left ? "│   " : "    "), node->left, true);
    print(prefix + (is_left ? "│   " : "    "), node->right, false);
}

template <typename T>
std::ostream &graph::operator<<(std::ostream &os, const graph::BinarySearchTree<T> &bst) {
    print("", bst.m_root, false);
    return os;
}

/*
void prettyPrintTree(TreeNode *node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if (node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}
*/
