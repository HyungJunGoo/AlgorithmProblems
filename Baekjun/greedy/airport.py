# 10775
import sys
sys.setrecursionlimit(15000)


def main():
    G = int(sys.stdin.readline())
    P = int(sys.stdin.readline())
    flights = []
    for _ in range(P):
        p = int(sys.stdin.readline())
        flights.append(p)
    gates = {i:i for i in range(G+1)}
    answer = 0
    for f in flights:
        root = find(gates,f)
        if root == 0:
            print(answer)
            return
        answer += 1
        union(gates, root, root-1)
    print(answer)
    return

def find(gates, flight):
    if gates[flight] != flight:
        p = find(gates, gates[flight])
        gates[flight] = p
        return p
    return gates[flight]

def union(gates, a_gate, b_gate):
    a_gate_root = find(gates, a_gate)
    b_gate_root = find(gates, b_gate)
    gates[a_gate_root] = b_gate_root
    return

if __name__ == "__main__":
    main()
    