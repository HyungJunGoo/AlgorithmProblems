# 4796

import sys

def main():

    i = 1
    while True:
        L, P, V = map(int, sys.stdin.readline().split())
        if L==0 and P==0 and V == 0:
            break
        a = (V//P)*L
        a += (V%P) if (V%P) < L else L
        print(f"Case {i}: {a}")
        i+=1
    return

if __name__ == "__main__":
    main()