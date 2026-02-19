class Solution:
    def maxValue(self, n: int, k: int) -> int:
        """
        将数字n分成k份，使得乘积最大，返回结果对1000000007取模
        """
        MOD = 1000000007
        if n % k == 0:
            return (n // k) ** k % MOD
        avg = n // k
        r = n % k
        ans = (avg + 1) ** r % MOD * avg ** (k - r) % MOD
        return ans
        

# 暴力递归（对数器验证用）
def brute_force(n, k):
    if k == 1:
        return n
    ans = float('-inf')
    for cur in range(1, n - k + 2):
        ans = max(ans, cur * brute_force(n - cur, k - 1))
    return ans


# 对数器
if __name__ == '__main__':
    import random
    N = 30
    test_times = 2000
    print("测试开始")
    sol = Solution()
    for i in range(1, test_times + 1):
        n = random.randint(1, N)
        k = random.randint(1, n)
        ans1 = brute_force(n, k)
        ans2 = sol.maxValue(n, k)
        if ans1 != ans2:
            print(f"出错了！n={n}, k={k}, 期望={ans1}, 实际={ans2}")
        if i % 100 == 0:
            print(f"测试到第{i}组")
    print("测试结束")