# 17413 <단어 뒤집기2>

s=list(input())
s2="" # return
tag=False
word=""
for c in s:
    if tag:
        if c == '>':
            tag=False
            word+=c
            s2+=word
            word=""
            continue
        word+=c
    if tag == False:
        if c=='<':
            tag=True
            word+=c
            continue
        if c == ' ':
            s2 += word + ' '
            word = ""
        else:
            word = c + word
s2+=word
print(s2)