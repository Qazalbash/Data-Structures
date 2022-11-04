from typing import Any, Optional


class Node:
    """A single Node in a binary tree."""

    def __init__(self: "Node",
                 value: Optional[object],
                 left: "Node" = None,
                 right: "Node" = None) -> None:
        self._value = value
        self._left = left
        self._right = right

    def __repr__(self: "Node") -> str:

        reprstr = f"Node(value: {self._value}, "

        if self._left == None:
            reprstr += f"left: {None}, "
        else:
            reprstr += f"left: {self._left._value}, "

        if self._right == None:
            reprstr += f"right: {None})"
        else:
            reprstr += f"right: {self._right._value})"

        return reprstr

    @property
    def value(self: "Node") -> Any:
        return self._value

    @value.setter
    def value(self: "Node", va: Any) -> None:
        self._value = va

    @property
    def left(self: "Node") -> "Node":
        return self._left

    @left.setter
    def left(self: "Node", l: Any) -> None:
        self._left = l

    @property
    def right(self: "Node") -> "Node":
        return self._right

    @right.setter
    def right(self: "Node", ri: Any) -> None:
        self._right = ri


class SkewHeap:
    """
    A SkewHeap is a heap data structure which uses an unbalanced binary tree to
    store items. Although no attempt is made to balance the tree, it can be
    shown to have amortized O(log n) time complexity for all operations under
    the assumption that the items inserted are in random order.
    """

    def __init__(self: "SkewHeap", items=tuple()):
        """
        SkewHeap() -> new, empty, skew heap.
        SkewHeap(iterable) -> new skew heap initialized from the iterable.
        """
        self.root: Node = None
        for item in items:
            self.push(item)

    def push(self: "SkewHeap", value: Any):
        """Add an item to this heap."""
        node = Node(value, None, None)
        self.root = self.merge(self.root, node)

    def pop(self: "SkewHeap"):
        """Remove the least item in this heap and return it."""
        if self.root is None:
            raise ValueError("Cannot pop empty SkewHeap")
        else:
            value = self.root.value
            self.root = self.merge(self.root.left, self.root.right)
            return value

    def peek(self: "SkewHeap"):
        """Return the least item in this heap without modifying this heap."""
        if self.root is None:
            raise ValueError("Cannot peek into empty SkewHeap")
        else:
            return self.root.value

    def union(self: "SkewHeap", other: "SkewHeap") -> "SkewHeap":
        """Return a new heap which contains all the items of this and another heap combined."""
        ret = SkewHeap()
        ret.root = self.merge(self.root, other.root)
        return ret

    def __add__(self: "SkewHeap", other: "SkewHeap") -> "SkewHeap":
        """The plus operator returns the union of two SkewHeaps."""
        return self.union(other)

    def __len__(self: "SkewHeap") -> int:
        """Return the number of items in this heap."""
        return self.count(self.root)

    def __bool__(self: "SkewHeap") -> bool:
        """Return true iff the heap is non-empty."""
        return self.root is not None

    def depth(self: "SkewHeap") -> int:
        """Return the depth of the tree used to represent this skew heap."""
        if self.root is None:
            return 0
        return 1 + max(self.depth(self.root.left), self.depth(self.root.right))

    def dfs(self: "SkewHeap", visited: list[Node], node: Node) -> list[Node]:
        if node not in visited:
            visited.append(node)
            neigh = []
            if node.left != None:
                neigh.append(node.left)
            if node.right != None:
                neigh.append(node.right)
            for neighbor in neigh:
                self.dfs(visited, neighbor)
        return visited

    @property
    def all_nodes(self: "SkewHeap") -> Optional[Any]:
        return [i.value for i in self.dfs([], self.root)]

    @staticmethod
    def merge(p: Optional[Node], q: Optional[Node]) -> Node:
        """
        Implements the critical "merge" operation which is
        used by all operations on a SkewHeap. The merge operation
        does not mutate either tree but returns a new tree which
        contains the least item at the root and is in heap order.
        The resulting tree is not necessarily balanced.
        """
        if p is None:
            return q
        if q is None:
            return p

        if q.value < p.value:
            p, q = q, p

        return Node(p.value, SkewHeap.merge(p.right, q), p.left)

    @staticmethod
    def count(node: Optional[Node]) -> int:
        """Count the total number of nodes in a tree rooted at this node."""
        if node is None:
            return 0
        return 1 + SkewHeap.count(node.left) + SkewHeap.count(node.right)