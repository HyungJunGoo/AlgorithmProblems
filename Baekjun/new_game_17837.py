# 17837  https://www.acmicpc.net/problem/17837

import sys


class Node:
    def __init__(self, n, col, row, d):
        self.number = n
        self.col = col
        self.row = row
        self.d = d
        self.above = []
        self.below = []
        self.available = True

chess_board = None
N = None
node_list = []

def main():

    N, K = map(int, sys.stdin.readline().split())
    chess_board = [[0 for _ in range(N)] for _ in range(N)]
    for row in range(N):
        row_list = sys.stdin.readline().split()
        for col in range(N):
            chess_board[row][col] += int(row_list[col])
    for i in range(K):
        row, col, d = map(int, sys.stdin.readline().split())
        node_list.append(Node(i+1, col, row, d))

    turn = 1

    while turn <= 1000:
        for node_num in range(K):
            move_node(node_list[node_num])
        turn += 1    

    return

def move_node(node):

    if node.d == 1: # right

        if node.col == N: #can not move go reverse way
            possible_bottom_nodes = []
            for n in node_list:
                if n.col == N-1 and n.row == node.row and len(n.above) == 0:
                    possible_bottom_nodes.append(n)
                    for below_of_n in n.bottom:
                        possible_bottom_nodes.append(below_of_n)
                    break

            if chess_board[node.row][node.col - 1] == 2: #cannot move anymore
                node.available = False
            else: # go to reverse way
                node.col -= 1
                node.d = 2
                for n in node.above:
                    n.col -= 1
                
                if chess_board[node.row][node.col] == 1: # Red
                    node.above = node.above.reverse()
                node.bottom = possible_bottom_nodes
                possible_bottom_nodes[0].above = node.above
                possible_bottom_nodes[0].above.append(node)
        else:
            possible_bottom_nodes = []
            for n in node_list:
                if n.col == node.col+1 and n.row == node.row and len(n.above) == 0:
                    possible_bottom_nodes.append(n)
                    for below_of_n in n.bottom:
                        possible_bottom_nodes.append(below_of_n)
                    break
            node.col += 1
            for n in node.above:
                n.col += 1
            node.bottom = possible_bottom_nodes
            possible_bottom_nodes[0].above = node.above
            possible_bottom_nodes[0].above.append(node)
        
    elif node.d == 2: #left
        if node.col == 0: #can not move go reverse way
            possible_bottom_nodes = []
            for n in node_list:
                if n.col == 1 and n.row == node.row and len(n.above) == 0:
                    possible_bottom_nodes.append(n)
                    for below_of_n in n.bottom:
                        possible_bottom_nodes.append(below_of_n)
                    break

            if chess_board[node.row][node.col + 1] == 2: #cannot move anymore
                node.available = False
            else: # go to reverse way
                node.col -= 1
                node.d = 2
                for n in node.above:
                    n.col -= 1
                node.bottom = possible_bottom_nodes
                possible_bottom_nodes[0].above = node.above
                possible_bottom_nodes[0].above.append(node)
        else:
            possible_bottom_nodes = []
            for n in node_list:
                if n.col == node.col+1 and n.row == node.row and len(n.above) == 0:
                    possible_bottom_nodes.append(n)
                    for below_of_n in n.bottom:
                        possible_bottom_nodes.append(below_of_n)
                    break
            node.col += 1
            for n in node.above:
                n.col += 1
            node.bottom = possible_bottom_nodes
            possible_bottom_nodes[0].above = node.above
            possible_bottom_nodes[0].above.append(node)
    elif node.d == 3: #up
        pass
    else: #bottom
        pass
    

if __name__ == "__main__":
    main()