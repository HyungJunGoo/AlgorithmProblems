# 괄호변환
# 2020 카카오 블라인드

# 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
# 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
# 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
#   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
# 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
#   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
#   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
#   4-3. ')'를 다시 붙입니다. 
#   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
#   4-5. 생성된 문자열을 반환합니다.
def balance(w):
    if w.count('(') == w.count(')'):
        if w.count('(') != 0:
            return True
    return False

def correct(w):
    l,r = 0,0
    if w[0] == ')':
        return False
    for c in w:
        if c == '(':
            l += 1
        elif c == ')':
            r += 1
        if l < r:
            return False
    return True

def rev(u):
    result = ""
    for c in u:
        if c == '(':
            result += ')'
        else:
            result += '('
    return result

def solution(p):
    answer = ''
    u,v = "", ""
    if len(p)==0:
        return ""
    for i in range(len(p)+1):
        if balance(p[:i]):
            u += p[:i]
            v += p[i:]
            break
    
    if correct(u):
        answer += u+solution(v)
    else:
        t = "("
        t += solution(v) + ")"
        u = u[1:]
        u = u[:-1]
        u = rev(u)
        t += u
        answer += t
        
    return answer