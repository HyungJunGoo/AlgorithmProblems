# 19235 <모노미노도미노>
# Not Solved
import sys
import copy
input = lambda: sys.stdin.readline()
T = (1,1), (1,2), (2,1)
bb=[list(0 for _ in range(6)) for _ in range(4)]
gb=[list(0 for _ in range(4)) for _ in range(6)]
score=0
X = 1
def addBlock(t, i, j):
    if t == 1:
        # 1X1
        #Blue
        for col in range(6):
            if col == 5:
                bb[i][col]=X
                break
            if bb[i][col+1] != 0:
                bb[i][col]=X
                break
        #Green
        for row in range(6):
            if row == 5:
                gb[row][j] = X
                break
            if gb[row+1][j] != 0:
                gb[row][j]=X
                break

    elif t == 2:
        #1X2
        #Blue
        for col in range(5):
            if col == 4:
                bb[i][col]=X
                bb[i][col+1]=X
                break
            if bb[i][col+2]!=0 and bb[i][col+1]==0 and bb[i][col]==0:
                bb[i][col]=X
                bb[i][col+1]=X
                break
        #Green
        for row in range(6):
            if row == 5:
                gb[row][j]=X
                gb[row][j+1]=X
                break
            if gb[row+1][j]!=0 or gb[row+1][j+1] !=0:
                gb[row][j]=X
                gb[row][j+1]=X
                break
    elif t ==3:
        # Blue
        for col in range(6):
            if col == 5:
                bb[i][col]=X
                bb[i+1][col]=X
                break
            if bb[i][col+1] != 0 or bb[i+1][col+1] != 0:
                bb[i][col]=X
                bb[i+1][col]=X
                break
        # Green
        for row in range(5):
            if row == 4 and gb[row][j]==0 and gb[row+1][j]==0:
                gb[row][j]=X
                gb[row+1][j]=X
                break
            if gb[row+2][j] != 0 and gb[row+1][j] == 0 and gb[row][j]==0:
                gb[row][j]=X
                gb[row+1][j]=X
                break
    X+=1    
    return

def updateBlock():
    global score
    # Blue
    checkCol = 5
    while checkCol > 0:
        condition = True
        for row in range(4):
            if bb[row][checkCol] == 0:
                condition=False
                break
        if condition: #점수 발생
            score+=1
            for row in range(4):
                bb[row][checkCol] = 0
            moveBlue()
        else:
            checkCol-=1

    # Green
    checkRow = 5
    while checkRow >0:
        condition = True
        for col in range(4):
            if gb[checkRow][col] == 0:
                condition=False
                break
        if condition:
            score+=1
            for col in range(4):
                gb[checkRow][col]=0
            moveGreen()
        else:
            checkRow-=1
    return

def moveBlue():
    
    
    ##
    for row in range(4):
        cnt=0
        for col in range(6):
            if bb[row][col] == 1:
                cnt += 1
                bb[row][col]=0
        for col in range(5,-1,-1):
            if cnt > 0:
                bb[row][col]=1
                cnt-=1

def moveGreen():
    
    for col in range(4):
        cnt=0
        for row in range(6):
            if gb[row][col] == 1:
                cnt += 1
                gb[row][col]=0
        for row in range(5, -1, -1):
            if cnt > 0:
                gb[row][col] = 1
                cnt -=1
            
    return

def specialCheck():
    #Todo
    # Blue
    blueCnt=0
    for col in range(2):
        condition=True
        for row in range(4):
            if bb[row][col] != 0:
                blueCnt+=1
                break

    # blueCnt 만큼 (1 or 2)
    if blueCnt >0:
        for _ in range(blueCnt):
            for row in range(4):
                bb[row].insert(0,0)
                bb[row].pop()
        
    # Green
    greenCnt=0
    for row in range(2):
        condition=True
        for col in range(4):
            if gb[row][col] != 0:
                greenCnt+=1
                break

    # greenCnt 만큼 (1 or 2)
    if greenCnt >0:
        for _ in range(greenCnt):
            for col in range(4):
                for row in range(5, 0, -1):
                    gb[row][col] = gb[row-1][col]
                gb[0][col] = 0
    return

def countCheck():
    cnt = 0
    for row in range(4):
        for col in range(6):
            if bb[row][col] != 0:
                cnt+=1
    for row in range(6):
        for col in range(4):
            if gb[row][col] != 0:
                cnt+=1
    print(cnt)
    return

if __name__ == "__main__":
    N=int(input())
    for _ in range(N):
        t, i, j = list(map(int, input().split()))
        addBlock(t,i,j)

        t_score = copy.copy(score)
        
        updateBlock()
        while score != t_score:
            updateBlock()
            t_score = copy.copy(score)
        specialCheck()

    print(score)
    countCheck()