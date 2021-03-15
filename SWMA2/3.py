import sys

sys.setrecursionlimit(10*8)
input = lambda: sys.stdin.readline()

N=int(input())
b=[list(map(int, input().split())) for _ in range(N)]


def divide(rstart, rend, cstart, cend):
    # row start, row end, col start, col end, verticalorlateral
    print(f"{rstart, rend, cstart, cend}")
    if rstart==rend and cstart==cend: return 0
    max_value=0
    for r in range(rstart, rend+1):
        for c in range(cstart, cend+1):
            max_value= max(b[r][c],max_value)
    
    rlen=rend-rstart+1
    clen=cend-cstart+1

    if rlen>1:
        nrstart=(N-1)-rend
        nrend=(N-1)-rstart
    elif rlen==1:
        nrstart=rstart
        nrend=rend
    if clen>1:
        ncstart=(N-1)-cend
        ncend=(N-1)-cstart
    elif clen==1:
        ncstart=cstart
        ncend=cend

    c1=divide(nrstart, nrend, ncstart, (ncstart+ncend)//2)
    c2=divide(nrstart, nrend, (ncstart+ncend)//2+1, ncend)
    c3=divide(nrstart, (nrstart+nrend)//2, ncstart, ncend)
    c4=divide((nrstart+nrend)//2+1, nrend, ncstart, ncend)
    return max_value+max(c1,c2,c3,c4)
c1=divide(0, (N-1)//2, 0, N-1) #0,1,0,3
c2=divide((N-1)//2+1, N-1, 0, N-1)#2,3,0,3
c3=divide(0, N-1, 0, (N-1)//2)#0,3,0,1
c4=divide(0, N-1, (N-1)//2+1, N-1)#0,3,2,3

print(c1,c2,c3,c4)