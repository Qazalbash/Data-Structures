from typing import Optional, overload


class Node:

    node_number: int = 0

    def __init__(self: "Node",
                 value: object = None,
                 left: "Node" = None,
                 right: "Node" = None) -> None:
        self._value = value
        self._left = left
        self._right = right
        Node.node_number += 1

    @property
    def value(self: "Node") -> object:
        return self._value

    @value.setter
    def value(self: "Node", v: "Node") -> None:
        self._value = v

    @value.deleter
    def value(self: "Node") -> None:
        self._value = None

    @property
    def left(self: "Node") -> "Node":
        return self._left

    @left.setter
    def left(self: "Node", l: "Node") -> None:
        self._left = l

    @left.deleter
    def left(self: "Node") -> None:
        self._left = None

    @property
    def right(self: "Node") -> "Node":
        return self._right

    @right.setter
    def right(self: "Node", r: "Node") -> None:
        self._right = r

    @right.deleter
    def right(self: "Node") -> None:
        self._right = None

    @property
    def children(self) -> Optional["Node"]:
        child = []
        if self._left == None:
            child.append(self._left)
        if self._right == None:
            child.append(self._right)
        return child

    def __bool__(self) -> bool:
        return self._value == None

    def __hash__(self) -> int:
        return hash((Node.node_number, self.value, self.left, self.right))

    def __repr__(self) -> str:
        return f"[value: {self._value}, left: {self._left}, right: {self._right}]"


class bst:

    def __init__(self: "bst", root: Node = None) -> None:
        self._root = root

    @property
    def root(self: "bst") -> Node:
        return self._root

    @root.setter
    def root(self: "bst", r: Node) -> None:
        self._root = r

    @root.deleter
    def root(self: "bst") -> None:
        self._root = None

    def insert(self: "bst", value: object, node: Node) -> None:
        if node:
            if node.value <= value:
                self.insert(value, node.left)
            else:
                self.insert(value, node.right)
        else:
            node.value = value

    def traverse(self: "bst", node: Node,
                 collection: set = set()) -> Optional[Node]:
        collection.add(node)
        for child in node.children:
            if child not in collection:
                self.traverse(child, collection)
        return collection

    @overload
    def __add__(self: "bst", other: Node) -> None:
        self.insert(self._root, other.value)

    @overload
    def __add__(self: "bst", other: "bst") -> None:
        for child in other.traverse(other.root):
            self = self + child

    def __bool__(self: "bst") -> bool:
        return self._root == None
