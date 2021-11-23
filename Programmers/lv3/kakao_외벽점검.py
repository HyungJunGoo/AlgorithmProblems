 https://programmers.co.kr/learn/courses/30/lessons/60062
from itertools import permutations


def solution(n, weak, dist):

    dist.sort(reverse=True)

    def _valid_check(m_list):

        combi = []
        for i in range(len(weak)):
            _combi = []
            for l in range(len(weak)):
                if i + l < len(weak):
                    _combi.append(weak[i + l])
                else:
                    _combi.append(n + weak[(i + l) % len(weak)])
            combi.append(_combi)

        for _combi in combi:
            bit_weak = 0
            mark = 0
            for w in _combi:
                bit_weak |= 1 << w
            for i in range(len(m_list)):
                i_m = m_list[i]
                if i == 0:
                    p = _combi[i]
                else:
                    for _p in _combi:
                        if _p > mark:
                            p = _p
                            break
                for b in range(p, p + dist[i_m] + 1):
                    if bit_weak & 1 << b:
                        bit_weak ^= 1 << b
                mark = p + dist[i_m]
            if not bit_weak:
                return True
        return False

    m_list = []
    for i in range(len(dist)):
        m_list.append(i)
        combi_m = list(map(list, permutations(m_list, len(m_list))))
        for cm in combi_m:
            if _valid_check(cm):
                return i + 1

    return -1
