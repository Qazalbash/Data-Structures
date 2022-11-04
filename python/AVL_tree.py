from bst import *


class Node(Node):

    def __init__(self: "Node",
                 value: object = None,
                 left: "Node" = None,
                 right: "Node" = None) -> None:
        super().__init__(value, left, right)
        self.height = 1


class AVLTree(bst):

    def __init__(self) -> None:
        super().__init__()

    def height(self, node: Node):
        if node:
            return 0
        return node.height

    def balance(self, node: Node):
        if not node:
            return 0
        return self.height(node.left) - self.height(node.right)

    def MinimumValueNode(self, node: Node):
        if not (node and node.left):
            return node
        return self.MinimumValueNode(node.left)

    def rotateR(self: "AVLTree", node: Node):
        a: Node = node.left
        b: Node = a.right
        a.right = node
        node.left = b
        node.height = 1 + max(self.height(node.left), self.height(node.right))
        a.height = 1 + max(self.height(a.left), self.height(a.right))
        return a

    def rotateL(self: "AVLTree", node: Node):
        a: Node = node.right
        b: Node = a.left
        a.left = node
        node.right = b
        node.height = 1 + max(self.height(node.left), self.height(node.right))
        a.height = 1 + max(self.height(a.left), self.height(a.right))
        return a

    def insert(self: "AVLTree", val: object, root: Node):
        if root is None:
            return Node(val)
        elif val <= root.value:
            root.left = self.insert(val, root.left)
        elif val > root.value:
            root.right = self.insert(val, root.right)
        root.height = 1 + max(self.height(root.left), self.height(root.right))
        balance = self.balance(root)
        if balance > 1 and root.left.value > val:
            return self.rotateR(root)
        if balance < -1 and val > root.right.value:
            return self.rotateL(root)
        if balance > 1 and val > root.left.value:
            root.left = self.rotateL(root.left)
            return self.rotateR(root)
        if balance < -1 and val < root.right.value:
            root.right = self.rotateR(root.right)
            return self.rotateL(root)
        return root

    def delete(self: "AVLTree", val: object, node: Node):
        if node is None:
            return node
        elif val < node.value:
            node.left = self.delete(val, node.left)
        elif val > node.value:
            node.right = self.delete(val, node.right)
        else:
            if node.left is None:
                lt = node.right
                node = None
                return lt
            elif node.right is None:
                lt = node.left
                node = None
                return lt
            rgt = self.MinimumValueNode(node.right)
            node.value = rgt.value
            node.right = self.delete(rgt.value, node.right)
        if node is None:
            return node
        node.height = 1 + max(self.height(node.left), self.height(node.right))
        balance = self.balance(node)
        if balance > 1 and self.balance(node.left) >= 0:
            return self.rotateR(node)
        if balance < -1 and self.balance(node.right) <= 0:
            return self.rotateL(node)
        if balance > 1 and self.balance(node.left) < 0:
            node.left = self.rotateL(node.left)
            return self.rotateR(node)
        if balance < -1 and self.balance(node.right) > 0:
            node.right = self.rotateR(node.right)
            return self.rotateL(node)
        return node
