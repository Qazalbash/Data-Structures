import re
from pathlib import Path
from typing import Optional


class Node(object):

    def __init__(self) -> None:
        self.children: dict = {}


class Document:

    def __init__(self, path: str) -> None:

        path: Path = Path(path)
        self.doc_id = str(path)[7:].replace("\\", "/")
        self.word_loc_map = {}
        self.size = 0

        content = path.read_text(encoding="ascii", errors="ignore")
        self.__tokenize_document(
            re.sub(r"[^\w\s]", "", content).replace("\n", " "))

    def __tokenize_document(self, content: str) -> None:
        start = 0
        while start < len(content):

            if content[start].isalnum():

                stop = content.find(" ", start)
                word = content[start:stop]
                self.word_loc_map[word] = self.word_loc_map.get(
                    word, []) + [(self.doc_id, start, stop)]

                start = stop + 1
                self.size += 1

            else:
                start += 1


class Trie:

    ENDWORD: str = "^"

    def __init__(self) -> None:

        self._root: Node = Node()

    @property
    def tree(self):
        return self._root

    @tree.setter
    def tree(self, doc: Document) -> None:

        for word, locs in doc.word_loc_map.items():
            node = self._root
            # adding words
            for letter in word:

                if letter not in node.children:
                    node.children[letter] = Node()

                node = node.children[letter]

            if Trie.ENDWORD not in node.children:
                node.children[Trie.ENDWORD] = locs

            else:
                node.children[Trie.ENDWORD].extend(locs)

    def complete(
            self,
            word: str) -> Optional[tuple[str, Optional[tuple[str, int, int]]]]:

        tokenized_word = word.split()  # prefix tokenization

        matches = {}

        for w in tokenized_word:
            s = self.match(self._root, w, w)

            for i, locs in s:
                matches[i] = matches.get(i, []) + locs

        return matches

    @staticmethod
    def match(node: Node, prefix: str,
              trace: str) -> Optional[tuple[str, Optional[str]]]:

        prefix_matching = []

        if prefix == trace:

            for prefix_char in trace:

                if prefix_char not in node.children:
                    return prefix_matching

                node = node.children[prefix_char]

        for postfix_char in node.children:

            if postfix_char == Trie.ENDWORD:
                prefix_matching.extend([(trace, node.children[postfix_char])])

            else:
                prefix_matching.extend(
                    Trie.match(node.children[postfix_char], prefix,
                               trace + postfix_char))

        return prefix_matching
