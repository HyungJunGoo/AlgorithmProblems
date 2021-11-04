# https://leetcode.com/problems/baic-calculator/
class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        value = 0
        oper = 1
        i = 0
        while i < len(s):
            if s[i] == " ":
                i += 1
                continue
            if s[i].isdigit():
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = 10 * num + int(s[i])
                    i += 1
                value += num * oper
                continue
            if s[i] in ["-", "+"]:
                oper = 1 if s[i] == "+" else -1

            if s[i] == "(":
                stack.append(value)
                stack.append(oper)
                value, oper = 0, 1
            if s[i] == ")":
                value *= stack.pop()
                value += stack.pop()
            i += 1
        return value


if __name__ == "__main__":
    s = Solution()

    # assert s.calculate("1 + 1") == 2
    # assert s.calculate(" 2-1 + 2 ") == 3
    # assert s.calculate("(1+(4+5+2)-3)+(6+8)") == 23
    # assert s.calculate("-2+ 1") == -1
    # assert s.calculate("-3") == -3
    # assert s.calculate("(-3)+6") == 3
    # assert s.calculate("- (3 + (4 + 5))") == -12
    # assert s.calculate("(7)-(0)+(4)") == 11
    # assert s.calculate("(5-(1+(5)))") == -1
    # assert s.calculate("2-4-(8+2-6+(8+4-(1)+8-10))") == -15
    print(s.calculate("2-4-(8+2-6+(8+4-(1)+8-10))"))
