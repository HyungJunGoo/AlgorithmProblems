# 괄호의 값
# https://www.acmicpc.net/problem/2504
import sys

input = lambda: sys.stdin.readline()


def match(top, paren):
    if top == "(":
        return paren == ")"
    elif top == "[":
        return paren == "]"


def solution(parens):
    answer = 0
    stack = []
    for paren in parens:
        if paren not in ["(", ")", "[", "]"]:
            return 0
        if paren == "(" or paren == "[":
            stack.append(paren)

        else:
            if len(stack) == 0:
                return 0
            top = stack.pop()
            if top == "(" or top == "[":
                if not match(top, paren):
                    return 0
                val = 2 if top == "(" else 3
                stack.append(val)
            else:  # 마지막으로 담긴 stack의 top이 숫자일 때,
                to_add = top
                while len(stack) > 0:
                    if stack[len(stack) - 1] not in ["(", "["]:
                        try:
                            to_add += stack.pop()
                        except TypeError:
                            return 0
                    else:
                        break
                if len(stack) > 0:
                    top = stack.pop()
                    if not match(top, paren):
                        return 0
                    val = 2 if top == "(" else 3
                    stack.append(val * to_add)
    try:
        answer += sum(stack)
    except TypeError:
        return 0

    return answer


print(solution(input().splitlines()[0]))
