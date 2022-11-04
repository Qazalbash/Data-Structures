from random import randint
from typing import Optional


class Node(object):

    def __init__(self: "Node", data: int = None, height: int = 0) -> None:
        self.data = data
        # height of the current node
        self._height = height
        # a list of next pointers
        self.next = [None] * (height + 1)

    def __repr__(self: "Node") -> str:
        return f"[{self.K}, {self.V}, {len(self.next)}]"

    @property
    def height(self: "Node") -> int:
        return self._height

    @property
    def key(self: "Node") -> object:
        return self.data[0]

    @property
    def value(self: "Node") -> object:
        return self.data[1]


class SkipList(object):

    def __init__(self: "SkipList") -> None:
        self.head = Node(None)
        self.level = 0  # height of the highest tower in the list so far
        self._size = 0

    def __len__(self: "SkipList") -> int:
        return self._size

    def _repr_(self: "SkipList") -> str:
        """Returns a string representation of this skiplist.
        Implement object representation that helps you debug.
        Parameters:
        - self: mandatory reference to this object
        Returns:
        this skiplist's string representation.
        """
        if self._size == 0:
            return "None"
        else:
            string = ""
            head = self.head
            for i in range(self.level - 1, -1, -1):
                string = string + "Level: " + str(i)
                current_node = head.next[i]
                while current_node:
                    string = (string + "(" + str(current_node.data[0]) + " " +
                              str(current_node.data[1]) + ")" + ",  ")
                    current_node = current_node.next[i]
                string += "\n"
            print(string)
            return string

    def __str__(self: "SkipList") -> str:
        """Returns a string representation of this skiplist.
        See the
        Parameters: given link for the difference between the __repr__ and __str__
        methods: https://www.geeksforgeeks.org/str-vs-repr-in-python/
        - self: mandatory reference to this object
        Returns:
        this skiplist's string representation.
        """
        return self.__repr__()

    def _search_path(self: "SkipList", key: object) -> list[Node]:
        """Returns the search path in this skiplist for key.
        The search path contains one node for each level of the skiplist
        starting from the highest and ending at level 0. The node for each
        level is the one corresponding to a descend in the search path.
        Parameters:
        - self: mandatory reference to this object
        - key: the key being searched for
        Returns:
        the descend nodes at each level of the skiplist, ordered from highest
        level to level 0.
        """
        lst = []
        current_node = self.head
        for i in reversed(range(self.level)):
            while current_node.next[i] and current_node.next[i].data[0] <= key:
                current_node = current_node.next[i]
                lst.append(current_node.data)
        if current_node and current_node.data[0] == key:
            return lst
        else:
            return None

    def _find_prev(self: "SkipList", key: object) -> Node:
        """Returns the node in the skiplist that contains the predecessor key.
        Parameters:
        - self: mandatory reference to this object
        - key: the key being searched for
        Returns:
        the node in the skiplist that contains the predecessor key.
        """
        current_node = self.head
        for i in reversed(range(self.level)):
            while current_node.next[i] and current_node.next[i].data[0] < key:
                current_node = current_node.next[i]
        if current_node.next[0] and current_node.next[0].data[0] == key:
            return current_node
        else:
            return None

    def reset(self: "SkipList") -> None:
        """Empty the skiplist.
        Parameters:
        - self: mandatory reference to this object
        Returns:
        None
        """
        self.level = 0  # height of the highest tower in the list so far
        self._size = 0
        # self.height = 0
        self.head = Node(None)

    @property
    def height(self: "SkipList") -> int:
        """Returns the height of the skiplist.
        The height is the largest level of the sentinel's tower.
        Parameters:
        - self: mandatory reference to this object
        Returns:
        the height of this skiplist.
        """
        return self.level

    def find(self: "SkipList", key: object) -> Optional[object]:

        current_node = self.head
        i = self.level - 1
        while i >= 0:
            #         for i in reversed(range(self.level)):
            while current_node.next[i] and current_node.next[i].data[0] < key:
                current_node = current_node.next[i]
            i -= 1
        current_node = current_node.next[0]
        # print(current_node.data[0], "key = ", key)
        if current_node and current_node.data[0] == key:
            return current_node.data[1]
        else:
            return None

    def find_range(self: "SkipList", key1: object,
                   key2: object) -> list[object]:
        if key1 > key2:
            return None
        current_node = self.head
        lst = []
        for i in reversed(range(self.level)):
            while current_node.next[i] and current_node.next[i].data[0] < key1:
                current_node = current_node.next[i]
        current_node = current_node.next[0]
        if current_node and current_node.data[0] == key1:
            while current_node and current_node.data[0] != key2:
                lst.append(current_node.data[1])  # data[1]
                current_node = current_node.next[0]
            lst.append(current_node.data[1])
            return lst
        else:

            print("not found")
            return None

    def remove(self: "SkipList", key: object) -> Optional[object]:
        """Returns the value stored for key in this skiplist and removes
        (key, value) from this skiplist, returns None if key is not stored in
        this skiplist.
        Parameters:
        - self: mandatory reference to this object
        - key: the key to be removed
        Returns:
        the stored value for key in this skiplist, None if key does not exist
        in this skiplist
        """
        update = [None] * (self.level)
        current = self.head
        for i in reversed(range(self.level)):
            while current.next[i] and current.next[i].data[0] < key:
                current = current.next[i]
            update[i] = current

        current = current.next[0]

        # If current node is target node
        if current != None and current.data[0] == key:
            for i in range(self.level):
                if update[i].next[i] != current:
                    break
                update[i].next[i] = current.next[i]

            # Remove levels having no elements
            while self.level > 0 and self.head.next[self.level - 1] == None:
                self.level -= 1

            return current.data[1]
        else:
            print("node not found")
            return None

    def insert(self: "SkipList", data: tuple[object, object]) -> None:
        current_node = self.head  # start from the top node
        node_level = self.randomHeight()

        # if length of the temporary node is greater than the height
        update_size = max(self.level, node_level)
        # this list will store the previous pointers for each level in the node to be created
        update = [None] * (update_size)
        # starts at the top level and moves down
        i = self.level - 1
        # for traversing from top to bottom
        while i >= 0:
            # for traversing from left to right
            while (current_node.next[i] != None
                   and current_node.next[i].data[0] < data[0]):
                current_node = current_node.next[i]
            # stores the current pointer before moving down
            update[i] = current_node
            i -= 1
        current_node = current_node.next[0]
        if current_node == None or current_node.data[0] != data[0]:
            temp_node = Node(data, node_level)
            if (
                    node_level > self.level
            ):  # if the new node is higher than  the height of the list, all extra previous pointers must be the head node
                i = self.level
                while i < node_level:
                    update[i] = self.head
                    self.head.next.append(None)
                    i += 1
            self.level = update_size
            i = 0
            while i != node_level:
                temp_node.next[i] = update[i].next[i]
                update[i].next[i] = temp_node
                i += 1
            self._size += 1
        else:
            current_node.data = data

    def randomHeight(self: "SkipList"):
        height = 1
        while randint(1, 2) != 1:
            height += 1
        return height

    @property
    def size(self: "SkipList") -> int:
        """Returns the number of pairs stored in this skiplist.
        Parameters:
        - self: mandatory reference to this object
        Returns:
        the number of pairs stored in this skiplist.
        """
        return self._size

    def is_empty(self: "SkipList") -> bool:
        """Returns whether the skiplist is empty.
        Parameters:
        - self: mandatory reference to this object
        Returns:
        True if no pairs are stored in this skiplist, False otherwise.
        """
        if self.head.next[0] == None:
            return True
        else:
            return False