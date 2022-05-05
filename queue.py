from typing import overload


class Queue:

    def __init__(self: "Queue", *values) -> None:
        self._queue = [val for val in values]

    @property
    def queue(self: "Queue") -> list:
        return self._queue

    @overload
    def enqueue(self: "Queue", *values: object) -> None:
        self._queue.extend(values)

    @overload
    def enqueue(self: "Queue", value: list) -> None:
        self._queue.extend(value)

    def dequeue(self: "Queue") -> object:
        return self._queue.pop(0)

    def clear(self: "Queue") -> None:
        self._queue.clear()