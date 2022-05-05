import re
from math import log10
from pathlib import Path
from typing import Optional


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


class InvertedIndex:

    def __init__(self) -> None:

        self._index_dict: dict = {}
        self._corpus_size: int = 0

    @property
    def indexs(self):
        return self._index_dict

    @indexs.setter
    def indexs(self, doc: Document) -> None:

        word_loc_map = doc.word_loc_map.items()

        for word, loc in word_loc_map:

            self._index_dict[word] = self._index_dict.get(word, {})
            self._index_dict[word][doc.doc_id] = len(loc) / doc.size

        self._corpus_size += 1

    def query(self, query_string: str, k: int) -> Optional[tuple[float, str]]:

        query_words = query_string.split()  # tokenizing query
        rank = {}

        for word in query_words:
            try:
                doc_freq = len(self._index_dict[word])
            except KeyError:
                continue

            for doc_id, tf in self._index_dict[word].items():
                rank[doc_id] = rank.get(
                    doc_id, 0) + tf * log10(self._corpus_size / doc_freq)

        k = (k - len(rank)) * (k < len(rank)) + len(rank)
        rank = [(tf_idfs, id) for id, tf_idfs in rank.items()]
        rank = sorted(rank, key=lambda k: k[0], reverse=True)
        return rank[:k]
