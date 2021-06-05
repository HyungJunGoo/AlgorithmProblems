"""
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 
Each move consists of turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, 
return the minimum total number of turns required to open the lock, or -1 if it is impossible.
"""
from collections import deque, defaultdict

class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """

        q = deque()
        q.append(("0000", 0))
        visited = defaultdict(lambda : False)
        visited["0000"] = True
        while len(q)>0:
            num, count = q.popleft()
            if num in deadends:
                continue
            if num == target:
                return count
            for i in range(4):
                ss = int(num[i])
                t1 = num[:i] + str((ss+1)%10) + num[i+1:]
                if ss > 0:
                    t2 = num[:i] + str(ss-1) + num[i+1:]
                else:
                    t2 = num[:i] + '9' + num[i+1:]
                if visited[t1] == False:
                    q.append((t1, count+1))
                    visited[t1] = True
                if visited[t2] == False:
                    q.append((t2, count+1))
                    visited[t2] = True
        return -1

deadends = ["0201","0101","0102","1212","2002"]
target = "0202"
s = Solution()
print(s.openLock(deadends, target))