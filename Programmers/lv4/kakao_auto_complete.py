class Node:
    def __init__(self, char):
        self.char = char
        self.count = 0
        self.next = {}
        self.leaf = False

class Trie:

    def __init__(self):
        self.root = Node(None)

    def insert(self, word):
        node = self.root
        word_l = len(word)
        for idx,char in enumerate(word):
            if char not in node.next:
                node.next[char] = Node(char)
            node = node.next[char]
            node.count += 1
            if idx == word_l-1:
                node.leaf = True

    def find(self, word, idx):
        node = self.root
        word_l = len(word)
        for i, char in enumerate(word):
            if node.next[char].count == 1 or i == word_l-1:
                return idx
            node = node.next[char]
            idx += 1
        return idx    

def solution(words):
    answer = 0
    trie = Trie()
    for word in words:
        trie.insert(word)
    for word in words:
        val = trie.find(word, 1)
        answer += val
    return answer

# words = ["go", "gone", "guild"]        
words = ["abc", "def", "ghi", "jklm"]        
print(solution(words))