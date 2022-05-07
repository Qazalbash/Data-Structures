class Stack:

    def __init__(self: "Stack", *values: object) -> None:
        self._stack = [val for val in values]

    @property
    def stack(self: "Stack") -> list:
        return self._stack

    @stack.deleter
    def stack(self: "Stack") -> None:
        del self._stack

    @property
    def top(self: "Stack") -> object:
        return self._stack[-1]

    def push(self: "Stack", *value: object) -> None:
        self._stack.extend(value)

    def pop(self: "Stack") -> object:
        return self._stack.pop()

    def clear(self) -> None:
        self._stack.clear()

    def __bool__(self: "Stack") -> bool:
        return len(self._stack) == 0

    def __add__(self: "Stack", value: object) -> "Stack":
        self.push(value)
        return self
