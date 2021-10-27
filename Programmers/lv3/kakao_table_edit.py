# https://programmers.co.kr/learn/courses/30/lessons/81303?language=python3

# n : 표의 갯수
# k : 현재 행의 위치
class Node:
    def __init__(self, n) -> None:
        self.n = n
        self.prev = None
        self.next = None


def solution(n, k, cmds):

    answer = ["O" for _ in range(n)]
    _nodes = []
    _deleted = []
    for i in range(n):
        _nodes.append(Node(i))
    _nodes[0].next = _nodes[1]
    _nodes[n - 1].prev = _nodes[n - 2]

    for i in range(1, n - 1):
        _nodes[i].prev = _nodes[i - 1]
        _nodes[i].next = _nodes[i + 1]

    for cmd in cmds:
        if cmd[0] == "U" or cmd[0] == "D":
            x = int(cmd.split(" ")[1])
            while x > 0:
                if cmd[0] == "U":

                    k = _nodes[k].prev.n
                elif cmd[0] == "D":
                    k = _nodes[k].next.n
                x -= 1

        elif cmd[0] == "C":
            _deleted.append(k)
            if _nodes[k].prev is not None:  # 맨 앞 아니라면
                _nodes[k].prev.next = _nodes[k].next
            if _nodes[k].next is not None:  # 맨 뒤 아니라면
                _nodes[k].next.prev = _nodes[k].prev
                k = _nodes[k].next.n
            else:  # 맨 뒤라면
                k = _nodes[k].prev.n

        elif cmd[0] == "Z":

            last = _deleted.pop()
            if _nodes[last].prev is not None:
                _nodes[last].prev.next = _nodes[last]
            if _nodes[last].next is not None:
                _nodes[last].next.prev = _nodes[last]
    for deleted_row in _deleted:
        answer[deleted_row] = "X"
    return "".join(answer)


assert (
    solution(8, 2, ["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"]) == "OOOOXOOO"
)
assert (
    solution(8, 2, ["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"])
    == "OOXOXOOO"
)
