class Queue:

    def __init__(self: "Queue", *values: object) -> None:
        """Constructor

        Args:
            self (Queue): mandatory object reference
        """
        self._queue = [val for val in values]

    @property
    def queue(self: "Queue") -> list:
        return self._queue

    def enqueue(self: "Queue", *values: object) -> None:
        self._queue.extend(values)

    def dequeue(self: "Queue") -> object:
        return self._queue.pop(0)

    def clear(self: "Queue") -> None:
        self._queue.clear()

    def __add__(self: "Queue", value: object) -> "Queue":
        self.enqueue(value)
        return self
