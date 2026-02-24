import random
from typing import List


# 平均值最小累加和
# 给定一个数组arr，长度为n，再给定一个数字k
# 必须将arr划分成k个非空集合（每个数字只能进一个集合）
# 返回每个集合的平均值（向下取整）累加起来的最小值
#
# 例1: arr = [1, 2, 3], k = 2
#   划分方式       各集合平均值(向下取整)   累加
#   {1} {2,3}      1 + 2 = 3             3
#   {2} {1,3}      2 + 2 = 4             4
#   {3} {1,2}      3 + 1 = 4             4
#   {1,2} {3}      1 + 3 = 4             4
#   {1,3} {2}      2 + 2 = 4             4
#   {2,3} {1}      2 + 1 = 3             3
#   最小 = 3
#
# 例2: arr = [1, 5, 7, 10], k = 3
#   最优: {1} {5} {7,10} → 1 + 5 + 8 = 14
#   观察: 最小的k-1个数各自独立成集合，剩余的数合并成一个集合
#
# 1 <= n <= 10^5, 0 <= arr[i] <= 10^5, 1 <= k <= n


class Solution:
    # 暴力方法 - 为了验证
    def minAverageSum1(self, arr: List[int], k: int) -> int:
        n = len(arr)
        sums = [0] * k
        cnts = [0] * k

        def f(i):
            if i == n:
                for j in range(k):
                    if cnts[j] == 0:
                        return float('inf')
                return sum(sums[j] // cnts[j] for j in range(k))
            ans = float('inf')
            for j in range(k):
                sums[j] += arr[i]
                cnts[j] += 1
                ans = min(ans, f(i + 1))
                sums[j] -= arr[i]
                cnts[j] -= 1
            return ans

        return f(0)

    # 正式方法 - 时间复杂度O(n * logn)
    def minAverageSum2(self, arr: List[int], k: int) -> int:
        arr.sort()
        ans = s = 0

        for i, x in enumerate(arr):
            if i <= k - 2:
                ans += x
            else:
                s += x
        
        return ans + s // (len(arr) - k + 1)


def main():
    N = 8
    V = 10000
    test_times = 2000
    print("测试开始")
    sol = Solution()
    for i in range(1, test_times + 1):
        n = random.randint(1, N)
        arr = [random.randint(0, V - 1) for _ in range(n)]
        k = random.randint(1, n)
        ans1 = sol.minAverageSum1(arr, k)
        ans2 = sol.minAverageSum2(arr, k)
        if ans1 != ans2:
            print(f"出错了！arr={arr}, k={k}, 期望={ans1}, 实际={ans2}")
        if i % 100 == 0:
            print(f"测试到第{i}组")
    print("测试结束")


if __name__ == "__main__":
    main()