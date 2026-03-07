import random
random.seed(42)
from itertools import combinations

"""
题目描述：
    仓库初始库存为 0，共 n 天，每天晚上执行 tasks[i]：
      - tasks[i] > 0：进货 tasks[i] 件
      - tasks[i] < 0：出货 |tasks[i]| 件（库存可变负）
      - tasks[i] == 0：检查日，库存不能为负
    经理可以在任意天的早上紧急进货（任意正整数），但任何时刻库存不能超过 max_products。
    求最少需要紧急进货的天数。无解返回 -1。

函数签名：
    def findMinimumDays(max_products: int, tasks: list[int]) -> int
"""


# ===================== 暴力解（枚举哪些天进货） =====================
def brute_force(max_products: int, tasks: list[int]) -> int:
    n = len(tasks)
    check_days = [i for i in range(n) if tasks[i] == 0]

    # 枚举进货天数从 0 到 n
    for num_days in range(n + 1):
        # 枚举在哪些天的早上进货
        for chosen in combinations(range(n), num_days):
            chosen_set = set(chosen)
            # 尝试确定每天进多少货，用贪心：每天进尽量少的货使后续合法
            # 简化：枚举每天进货量太大，改用 LP 思路
            # 这里用 DFS + 剪枝 来验证
            if _check(max_products, tasks, chosen_set, check_days):
                return num_days
    return -1


def _check(max_products, tasks, chosen_set, check_days):
    """
    给定哪些天进货，判断是否存在合法的进货量方案。
    贪心：在选定的进货日，尽量少进货使得下一个检查日刚好合法。
    但需要同时满足上界约束（任何时刻库存 <= max_products）。
    """
    n = len(tasks)
    stock = 0
    total_added = 0

    # 预处理：对每个进货日，计算到下一个检查日所需的最小进货量，以及路径上的最大库存
    add_days = sorted(chosen_set)

    # 模拟：在进货日加货，检查日验证
    # 尝试所有可能的进货量组合太慢，用约束求解
    # 简化方法：从左到右模拟，在进货日尽量多进（不超过 max_products 约束）
    stock = 0
    for i in range(n):
        if i in chosen_set:
            # 尽量多进货：此刻库存为 stock，最多加到 max_products
            # 但还要考虑 tasks[i] 执行后也不能超
            max_can_add_before = max_products - stock
            max_can_add_after = max_products - (stock + tasks[i]) if tasks[i] > 0 else float('inf')
            add = min(max_can_add_before, max_can_add_after)
            if add < 0:
                return False
            stock += add

        stock += tasks[i]

        if stock > max_products:
            return False
        if tasks[i] == 0 and stock < 0:
            return False

    return True


# ===================== 你的最优解 =====================
def findMinimumDays(max_products: int, tasks: list[int]) -> int:
    n = len(tasks)
    s = [0]
    for x in tasks:
        s.append(s[-1] + x)
    upper = [0] * (n + 1)
    for i in range(1, n + 1):
        upper[i] = max_products - max(s[i - 1], s[i])
        if upper[i] < 0:
            return -1
    suf = [0] * (n + 1)
    suf[-1] = upper[-1]
    for i in range(n - 1, 0, -1):
        suf[i] = min(suf[i + 1], upper[i])
    ans = a = 0
    for i, x in enumerate(tasks):
        if x == 0:
            if a + s[i] < 0:
                if suf[i + 1] + s[i] < 0:
                    return -1
                a = suf[i + 1]
                ans += 1
    return ans


# ===================== 标准解（已验证） =====================
def standard(max_products: int, tasks: list[int]) -> int:
    n = len(tasks)
    pre = [0]
    for x in tasks:
        pre.append(pre[-1] + x)

    U = [0] * (n + 1)
    for i in range(1, n + 1):
        U[i] = max_products - max(pre[i - 1], pre[i])
        if U[i] < 0:
            return -1

    suf = [0] * (n + 2)
    suf[n + 1] = float('inf')
    for i in range(n, 0, -1):
        suf[i] = min(U[i], suf[i + 1])

    D = 0
    ans = 0
    for i in range(1, n + 1):
        if tasks[i - 1] == 0:
            needed = -pre[i]
            if D < needed:
                if suf[i] < needed:
                    return -1
                D = suf[i]
                ans += 1
    return ans


# ===================== 随机数据生成器 =====================
def gen_random_case():
    n = random.randint(1, 8)
    max_products = random.randint(1, 20)
    tasks = []
    for _ in range(n):
        r = random.random()
        if r < 0.25:
            tasks.append(0)
        elif r < 0.6:
            tasks.append(random.randint(1, 15))
        else:
            tasks.append(-random.randint(1, 15))
    return max_products, tasks


# ===================== 对数器 =====================
def test():
    # 先跑固定用例
    fixed_cases = [
        (12, [-5, 0, 10, -13, 0], 2),
        (10, [7, -2, 0, 6], -1),
    ]
    for mp, tasks, expected in fixed_cases:
        std = standard(mp, tasks)
        mine = findMinimumDays(mp, tasks)
        assert std == expected, f"Standard failed on fixed case: {mp}, {tasks}"
        if mine is None:
            print("你的 findMinimumDays 还没实现，跳过对比。")
            return
        assert mine == expected, f"Your solution failed on fixed case: {mp}, {tasks}, expected={expected}, got={mine}"

    # 随机对拍
    num_tests = 5000
    for t in range(num_tests):
        mp, tasks = gen_random_case()
        expected = standard(mp, tasks)
        mine = findMinimumDays(mp, tasks)
        if mine != expected:
            print(f"MISMATCH on test #{t}:")
            print(f"  max_products = {mp}")
            print(f"  tasks = {tasks}")
            print(f"  expected = {expected}")
            print(f"  yours    = {mine}")
            return

    print(f"All {num_tests} random tests passed!")


if __name__ == "__main__":
    test()