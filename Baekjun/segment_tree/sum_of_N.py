# 2042번 

def init(node, start, end):
    
    if start == end:
        tree[node] = numbers[start]
        return tree[node]
    else:
        tree[node] = (init(node*2, start, (start+end)//2) + init(node*2+1, (start+end)//2+1, end))
        return tree[node]

def sum_of_section(node, start, end, left, right):
    
    if left > end or right < start: return 0
    if left <= start and end <=right:
        return tree[node]
    return sum_of_section(node*2, start, (start+end)//2, left, right) + sum_of_section(node*2+1, (start+end)//2+1, end, left, right)

def update_numbers(node, start, end, index, diff):
    
    if index < start or index > end: return

    tree[node] += diff

    if start != end:
        update_numbers(node*2, start, (start+end)//2, index, diff)
        update_numbers(node*2+1, (start+end)//2+1, end, index, diff)
        
numbers = []
tree = [0]*3000000

def main():
    l = input().split()
    N,M,K = int(l[0]), int(l[1]), int(l[2])
    for i in range(N):
        n = int(input())
        numbers.append(n)
    
    init(1, 0, N-1)

    for i in range(M+K):
        l = input().split()
        change_or_sum, a, b = int(l[0]), int(l[1]), int(l[2])
        if change_or_sum == 1:
            diff = b - numbers[a-1]
            numbers[a-1] = b
            update_numbers(1, 0, N-1, a-1, diff)
        else:
            print(sum_of_section(1, 0, N-1, a-1, b-1))
    return

if __name__ == "__main__":
    main()