# A naive Recursive implementation of Knapsack Problem

# Returns the maximum value that can be put in a knapsack of capacity W

def knapSack(W, wt, val, n):

    # BaseCase 
    if n == 0 or W == 0:
        return 0

    # If weight of the nth item is more than Knapsack of capacity W, then this item cannot be included in the optimal solution
    if (wt[n-1] > W):
        return knapSack(W, wt, val, n-1)

    # return the maximum of two cases:
    # case 1 : nth item included
    # case 2 : not included
    else:
        return max(
            val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1)
        )
    
def main():
    n, W = input().split()
    n = int(n)
    W = int(W)
    wt = list()
    val = list()
    for i in range(int(n)):
        w, v = input().split()
        wt.append(int(w))
        val.append(int(v))
    print(knapSack(W,wt,val, n))
    return

if __name__ == "__main__":
    main()