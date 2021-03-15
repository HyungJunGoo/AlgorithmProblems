import sys

def main():
    p, n, h = map(int, sys.stdin.readline().split())
    d = {i : [] for i in range(1, p+1)}

    for _ in range(n):
        x, y = map(int, sys.stdin.readline().split())
        d[x].append(y)
    for i in range(1, p+1):
        d[i] = sorted(d[i])
        util(i, d, h)
    
    
    return      

def util(i, d, h):
    t = 0
    l = len(d[i])
    for idx in range(l):
        if d[i][l-1-idx]+t <= h:
            t += d[i][l-1-idx]
    print(f"{i} {t *1000}")


if __name__=="__main__":
    main()