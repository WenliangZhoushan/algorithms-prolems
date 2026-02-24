import random
from heapq import *
from typing import List


# 组团买票
# 景区里一共有m个项目，每个项目有折扣系数ki和票价bi（均为正数）
# 如果有x个人买某项目的票，单张价格为 bi - ki * x
# x个人的总花费为 max(x * (bi - ki * x), 0)（不会倒贴钱）
# 单位共n个人，每人最多选1个项目游玩，也可以不选
# 员工自由选择，你需要准备足够的钱应对最坏情况
# 返回最保险的钱数（即所有选择方案中的最大总花费）
#
# 例1: n=2, games=[[1, 5]]
#   0人选: 花费0
#   1人选: max(1*(5-1), 0) = 4
#   2人选: max(2*(5-2), 0) = 6
#   最坏情况 = 6
#
# 例2: n=3, games=[[2, 10], [1, 4]]
#   项目0: 1人→8, 2人→12, 3人→12
#   项目1: 1人→3, 2人→4, 3人→3
#   比如1人选项目0, 1人选项目1: 8+3=11
#   比如2人选项目0, 1人选项目1: 12+3=15
#   比如2人选项目0, 0人选项目1: 12
#   最坏情况 = 15


class Solution:
    # 暴力方法 - 为了验证
    def enough1(self, n: int, games: List[List[int]]) -> int:
        m = len(games)
        cnts = [0] * m

        def f(i):
            if i == n:
                total = 0
                for j in range(m):
                    k, b = games[j]
                    x = cnts[j]
                    total += max((b - k * x) * x, 0)
                return total
            # 第i个人不选任何项目
            ans = f(i + 1)
            # 第i个人选第j个项目
            for j in range(m):
                cnts[j] += 1
                ans = max(ans, f(i + 1))
                cnts[j] -= 1
            return ans

        return f(0)

    # 正式方法 - 时间复杂度O(n * logm)
    def enough2(self, n: int, games: List[List[int]]) -> int:
        m = len(games)
        cnt = [0] * m

        def f(i):
            k, b = games[i]
            past_x = cnt[i]
            return b - k * (1 + past_x) - k * past_x

        h = []
        for i in range(m):
            heappush(h, (-f(i), i))
        ans = 0

        while n and h and -h[0][0] > 0:
            x, i = heappop(h)
            ans += -x
            cnt[i] += 1
            n -= 1
            heappush(h, (-f(i), i))
        
        return ans


def main():
    N = 8
    M = 8
    V = 20
    test_times = 2000
    print("测试开始")
    sol = Solution()
    for i in range(1, test_times + 1):
        n = random.randint(1, N)
        m = random.randint(1, M)
        games = [[random.randint(1, V), random.randint(1, V)] for _ in range(m)]
        ans1 = sol.enough1(n, games)
        ans2 = sol.enough2(n, games)
        if ans1 != ans2:
            print(f"出错了！n={n}, games={games}, 期望={ans1}, 实际={ans2}")
        if i % 100 == 0:
            print(f"测试到第{i}组")
    print("测试结束")


if __name__ == "__main__":
    main()
