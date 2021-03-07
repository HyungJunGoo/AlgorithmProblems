class Node:
    def __init__(self, value):
        self.value = value
        self.cnt  = 1
        self.end = False
        self.child = {}

class Trie:
    def __init__(self):
        self.root = Node("")

    def insert(self, value_list):
        node = self.root
        for value in value_list:
            # print(value)
            if value in node.child:
                # print(f"value in {node.value}'s child so input {value}")
                node = node.child[value]
                node.cnt += 1
            else:
                # print(f"value not in {node.value}'s child so input {value}")
                n_node = Node(value)
                node.child[value] = n_node
                node = n_node
        node.end = True
        
    def search(self, value_list):
        cnt = 0
        node = self.root
        for value in value_list:
            if value == '-':


def util(str_query):
    query_list = str_query.split(' ')
    query_list = [q for q in query_list if q!='and']
    return query_list

def solution(info, query):
    answer = []
    info_list = []
    for i in info:
        info_list.append(util(i))
    T = Trie()
    for i in info_list:
        T.insert(i)
    print(T.root.child['java'].cnt)
    return answer
info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]
solution(info, query)