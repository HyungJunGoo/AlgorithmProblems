# 2331 <반복 수열>

n,m = list(map(int, input().split()))

l=[n]
idx=0
while 1:
    a=l[len(l)-1]
    s=str(a)
    v=0
    for i in range(len(s)):
        v+=pow(int(s[i]),m)

    if v in l:
        for i,num in enumerate(l):
            if num==v:
                idx=i
                break
        break
    else:
        l.append(v)
print(idx)