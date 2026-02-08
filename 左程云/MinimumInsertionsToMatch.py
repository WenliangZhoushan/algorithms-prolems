# 完成配对需要的最少字符数量
# 给定一个由'['、']'、'('，')'组成的字符串
# 请问最少插入多少个括号就能使这个字符串的所有括号正确配对
# 例如当前串是 "([[])"，那么插入一个']'即可满足
# 输出最少需要插入多少个字符
# 测试链接 : https://www.nowcoder.com/practice/e391767d80d942d29e6095a935a5b96b

import random
random.seed(42)


# 正确解法（对数器用）
def correct_solution(s: str) -> int:
    if not s:
        return 0
    n = len(s)
    dp = [[-1] * n for _ in range(n)]
    
    def f(l, r):
        if l == r:
            return 1
        if l == r - 1:
            if (s[l] == '(' and s[r] == ')') or (s[l] == '[' and s[r] == ']'):
                return 0
            return 2
        if dp[l][r] != -1:
            return dp[l][r]
        p1 = float('inf')
        if (s[l] == '(' and s[r] == ')') or (s[l] == '[' and s[r] == ']'):
            p1 = f(l + 1, r - 1)
        p2 = float('inf')
        for m in range(l, r):
            p2 = min(p2, f(l, m) + f(m + 1, r))
        ans = min(p1, p2)
        dp[l][r] = ans
        return ans
    
    return f(0, n - 1)


# 你的解法
class Solution:
    def minInsertions(self, s: str) -> int:
        # 枚举长度的区间dp, ac
        n = len(s)
        f = [[0] * n for _ in range(n)]
        g = {"(": ")", "[": "]", "{": "}"}
        for i in range(n):
            f[i][i] = 1

        for l in range(2, n + 1):
            for i in range(0, n - l + 1):
                j = i + l - 1
                ans1 = ans2 = 1 << 16
                for k in range(i + 1, j):
                    ans1 = min(ans1, f[i][k] + f[k + 1][j])
                if g.get(s[i], "") == s[j]:
                    ans2 = min(ans2, f[i + 1][j - 1])
                else:
                    ans2 = min(ans2, min(f[i + 1][j], f[i][j - 1]) + 1)
                f[i][j] = min(ans1, ans2)
        
        return f[0][n - 1]

        # 下面两个都是考虑枚举左右端点
        # 先考虑划分，再考虑首尾
        n = len(s)
        f = [[0] * n for _ in range(n)]
        g = {"(": ")", "[": "]", "{": "}"}
        for i in range(n):
            f[i][i] = 1
 
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                ans = 1 << 16 # 如果先考虑划分，就要和ans比较，因为一开始f[i][j]是0，j是大于i的，直接min一直是0
                for k in range(i + 1, j):
                    ans = min(ans, f[i][k] + f[k + 1][j])
                f[i][j] = ans
                # 其实也可以考虑ans1和ans2，ans1就是划分匹配，ans2是首尾匹配
                if g.get(s[i], "") == s[j]:
                    f[i][j] = min(f[i][j], f[i + 1][j - 1])
                else:
                    f[i][j] = min(min(f[i + 1][j], f[i][j - 1]) + 1, f[i][j])

        return f[0][n - 1]

        '''ac版本，先考虑首位匹配，再考虑中间划分
        n = len(s)
        f = [[0] * n for _ in range(n)]
        g = {"(": ")", "[": "]", "{": "}"}
        for i in range(n):
            f[i][i] = 1
            # 多余的，首位匹配会覆盖掉
            # if i < n - 1:
            #     f[i][i + 1] = 0 if g.get(s[i], "") == s[i + 1] else 2
 
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if g.get(s[i], "") == s[j]:
                    f[i][j] = f[i + 1][j - 1]
                else:
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1
                for k in range(i + 1, j):
                    f[i][j] = min(f[i][k] + f[k + 1][j], f[i][j])

        return f[0][n - 1]
        '''

        '''栈匹配错误，反例 [(])，期望是4，输出0
        st = [[] for _ in range(3)]

        idx = {}
        for i, ch in enumerate("()[]{}"):
            idx[ch] = i // 2
        g = {"(" : ")", "[": "]", "{" : "}"}

        for i, ch in enumerate(s):
            j = idx[ch]
            if st[j] and g.get(s[st[j][-1]], "") == ch:
                st[j].pop()
                continue
            st[j].append(i)

        return sum(len(x) for x in st)
        '''
        

# 随机生成测试用例
def generate_random_string(max_len):
    length = random.randint(1, max_len)
    chars = ['[', ']', '(', ')']
    return ''.join(random.choice(chars) for _ in range(length))


# 对数器
def test():
    test_times = 10000
    max_len = 15
    sol = Solution()
    
    print("测试开始")
    for i in range(test_times):
        s = generate_random_string(max_len)
        ans1 = correct_solution(s)
        ans2 = sol.minInsertions(s)
        if ans1 != ans2:
            print(f"出错了!")
            print(f"测试用例: {s}")
            print(f"正确答案: {ans1}")
            print(f"你的答案: {ans2}")
            return
    print("测试结束，全部通过!")


if __name__ == "__main__":
    test()