# 2563 <색종이>

n=int(input())

b=[[0]*100 for _ in range(100)]

for _ in range(n):
    x,y=list(map(int, input().split()))
    for i in range(y-1, y+9):
        for j in range(x-1,x+9):
            if b[i][j] ==0:
                b[i][j]+=1
cnt=0
for i in range(100):
    for j in range(100):
        if b[i][j] == 1:
            cnt+=1
print(cnt)
