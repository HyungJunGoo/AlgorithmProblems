import sys
sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline()
in_index = None

def function(post_start, post_end, in_start, in_end):
    global postorder, inorder
    if post_start > post_end or in_start > in_end:
        return
    root = postorder[post_end]
    print(root, end=' ')
    root_idx = in_index[root]
    left = root_idx - in_start
    function(post_start, post_start+left-1, in_start, root_idx-1)
    function(post_start+left, post_end-1, root_idx+1, in_end)
    return

def solution(n, inorder, postorder):
    global in_index
    in_index = [0 for _ in range(n+1)]
    for i,v in enumerate(inorder):
        in_index[v] = i
    function(0,n-1,0,n-1)
    return

if __name__ == "__main__":
    n = int(input())
    inorder = list(map(int, input().split()))
    postorder = list(map(int, input().split()))
    solution(n, inorder, postorder)
    print()