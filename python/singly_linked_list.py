class Node:

    def __init__(self: "Node", value: object = None) -> None:
        self._value = value
        self._next: "Node" = None

    @property
    def value(self: "Node") -> object:
        return self._value

    @value.setter
    def value(self: "Node", va: object) -> None:
        self._value = va

    @value.deleter
    def value(self: "Node") -> None:
        self._value = None

    @property
    def next(self: "Node") -> "Node":
        return self._next

    @next.setter
    def next(self: "Node", ne: "Node") -> None:
        self._next = ne

    @next.deleter
    def next(self: "Node") -> None:
        self._next = None


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