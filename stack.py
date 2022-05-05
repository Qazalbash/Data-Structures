class Stack:

    def __init__(self: "Stack", *values: object) -> None:
        self._stack = [val for val in values]

    @property
    def stack(self: "Stack") -> list:
        return self._stack

    @property
    def top(self: "Stack") -> object:
        return self._stack[-1]

    def push(self: "Stack", *value: object) -> None:
        for val in value:
            self._stack.append(val)

    def pop(self: "Stack") -> object:
        return self._stack.pop()

    def is_empty(self: "Stack") -> bool:
        return len(self._stack) == 0

    def clear(self) -> None:
        self._stack.clear()
