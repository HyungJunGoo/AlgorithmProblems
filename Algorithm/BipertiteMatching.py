
a = [[],[1,2,3], [1],[2]]
try_get = [False for _ in range(4)]
p = [0,0,0,0,0]
count = 0
def dfs(x):
    for i in range(len(a[x])):
        y = a[x][i]
        if try_get[y]:
            continue
        else:
            try_get[y]=True
        if p[y] == 0 or dfs(p[y]):
            p[y] = x
            return True
    return False

for i in range(1,4):
    try_get = [False for _ in range(4)]
    if dfs(i):
        count += 1

for i in range(1,4):
    print(f"{p[i]} - > {i}")
print(count)