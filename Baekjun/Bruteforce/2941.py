#2941 <크로아티아 알파벳>

s=input()
cnt = 0
i=0
while i < len(s):
    if s[i]=='c':
        if i < len(s)-1 and (s[i+1]=='=' or s[i+1]=='-'):
            cnt+=1
            i+=2
            continue
    elif s[i] == 'd':
        if i<len(s)-2 and s[i+1] =='z' and s[i+2]=='=':
            cnt+=1
            i+=3
            continue
        elif i <len(s)-1 and s[i+1] == '-':
            cnt+=1
            i+=2
            continue
    elif s[i] == 'l' or s[i] == 'n':
        if i<len(s)-1 and s[i+1]=='j':
            cnt+=1
            i+=2
            continue
    elif s[i] == 's' or s[i]=='z':
        if i<len(s)-1 and s[i+1]=='=':
            cnt+=1
            i+=2
            continue

    cnt+=1
    i+=1
print(cnt)