from typing import Optional


class Node:

    def __init__(self: "Node", value: object = None) -> None:
        self.value = value
        self.next = None


class SinglyLinkedList:

    def __init__(self, size: int, value=None) -> None:
        self.head = prev = None
        self.size = size

        for _ in range(size):
            node = Node(value)
            if prev == None:
                prev = node
                self.head = node
            else:
                prev.next = node
            prev = node

    def __len__(self) -> int:
        return self.size

    def __getitem__(self, i: int):
        assert (
            0 <= i < len(self)
        ), f"Getting invalid list index {i} from list of size {len(self)}"
        current = self.head
        for _ in range(i):
            current = current.next
        return current.data

    def __setitem__(self, i: int, value) -> None:
        assert (
            0 <= i < len(self)
        ), f"Getting invalid list index {i} from list of size {len(self)}"
        current = self.head
        for _ in range(i):
            current = current.next
        current.data = value

    def set(self, index: int, value: tuple[int, int, int]) -> None:
        self.__setitem__(index, value)