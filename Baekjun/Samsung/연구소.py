from itertools import combinations
import copy

def spread_virus(i, j, tmp_map, N, M):
    # left
    for idx in range(j-1,-1,-1):
        if tmp_map[i][idx] == 0:
            tmp_map[i][idx] = 2
            tmp_map = spread_virus(i, idx, tmp_map, N, M)
        elif tmp_map[i][idx] == 1:
            break

    # right
    for idx in range(j,M):
        if tmp_map[i][idx] == 0:
            tmp_map[i][idx] = 2
            tmp_map = spread_virus(i, idx, tmp_map, N, M)
        elif tmp_map[i][idx] == 1:
            break
    # up
    for idx in range(i-1,-1,-1):
        if tmp_map[idx][j] == 0:
            tmp_map[idx][j] = 2
            tmp_map = spread_virus(idx, j, tmp_map, N, M)
        elif tmp_map[idx][j] == 1:
            break
    # bottom
    for idx in range(i,N):
        if tmp_map[idx][j] == 0:
            tmp_map[idx][j] = 2
            tmp_map = spread_virus(idx, j, tmp_map, N, M)
        elif tmp_map[idx][j] == 1:
            break
    return tmp_map

def get_area(N, M, map_info, wall_info, virus_info):
    total_area = N*M
    tmp_map = copy.deepcopy(map_info)
    for i, j in wall_info:
        tmp_map[i][j] = 1
    for i, j in virus_info:
        tmp_map = spread_virus(i,j,tmp_map, N, M)
    for i in range(N):
        for j in range(M):
            if tmp_map[i][j] != 0:
                total_area -= 1
    return total_area

def solution(N, M, map_info, virus_info):
    answer = []
    point_list = []
    for i in range(N):
        for j in range(M):
            if map_info[i][j] == 0:
                point_list.append((i,j))
    candidate = combinations(point_list, 3)
    for cand in candidate:
        answer.append(get_area(N,M,map_info, cand, virus_info))
    return max(answer)

def main():
    N, M = input().split()
    N = int(N)
    M = int(M)
    map_info = []
    virus_info = []
    for i in range(N):
        _l = input().split()
        l = [int(x) for x in _l]
        map_info.append(l)
    for i in range(N):
        for j in range(M):
            if map_info[i][j] == 2:
                virus_info.append((i, j))
    print(solution(N, M, map_info, virus_info))
    return

if __name__ == "__main__":
    
    main()