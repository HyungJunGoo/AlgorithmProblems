from collections import deque
def main():
    N = int(input())
    q = deque()
    for i in range(1, N+1):
        q.append(i)
    while N > 1:
        q.popleft()
        N -=1
        go_back = q.popleft()
        q.append(go_back)
    print(q.popleft())
    return
 
if __name__ == "__main__":
    main()