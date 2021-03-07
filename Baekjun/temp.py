import copy
def f(l, v):
    tmp = copy.copy(l)
    for i, j in enumerate(tmp):
        if j == v:
           tmp[i] = -1
    print(tmp)
    return tmp

def main():
    l = [1,2,3,4,3,3,7,8,9]

    t =f(l, 3)
    print(t)

main()