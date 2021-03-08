# 11726 <2n 타일>

n = int(input())

d=[0]*(n+1)

d[0] = 1
d[1] = 2
for i in range(2,n):
    d[i] = (d[i-1] + d[i-2])%10007
print(d[n-1])

