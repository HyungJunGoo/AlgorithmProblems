def solution(number):
    d = [0] * 12
    d[0] = 1
    d[1] = 1
    d[2] = 2
    for i in range(3, number+1):
        d[i] = d[i-1] + d[i-2] + d[i-3]
    return d[number]
        

def main():
    N = input()
    test_case = []
    for i in range(int(N)):
        n = input()
        print(solution(int(n)))
    return

if __name__ == "__main__":
    main()