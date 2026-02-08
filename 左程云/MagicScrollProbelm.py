import random
random.seed(42)
import heapq
import math

# // 魔法卷轴
# // 给定一个数组nums，其中可能有正、负、0
# // 每个魔法卷轴可以把nums中连续的一段全变成0
# // 你希望数组整体的累加和尽可能大
# // 卷轴使不使用、使用多少随意，但一共只有2个魔法卷轴
# // 请返回数组尽可能大的累加和
# // 对数器验证

class Solution:
    def max_sum_magic_scroll(self, nums: list[int]) -> int:
        if not nums:
            return 0
        a0 = sum(nums)

        n = len(nums)
        f1 = [0] * n
        f1[0] = 0
        pre = nums[0]
        mx_pre = max(nums[0], 0)
        for i in range(1, n):
            f1[i] = max(f1[i - 1] + nums[i], mx_pre)
            pre += nums[i]
            mx_pre = max(mx_pre, pre)
        a1 = max(f1)

        f2 = [0] * n
        f2[n - 1] = 0
        suf = nums[n - 1]
        mx_suf = max(0, nums[n - 1])
        for i in range(n - 2, -1, -1):
            f2[i] = max(f2[i + 1] + nums[i], mx_suf)
            suf += nums[i]
            mx_suf = max(mx_suf, suf)
        a2 = -math.inf
        for i in range(n - 1):
            a2 = max(a2, f1[i] + f2[i + 1])

        return max(a0, a1, a2)
# ---------------------------------------------------------
# 验证区域：暴力方法与对数器
# ---------------------------------------------------------

def must_one_scroll(nums, l, r):
    ans = float('-inf')
    # 枚举所有可能的 a...b 范围变 0
    for a in range(l, r + 1):
        for b in range(a, r + 1):
            cur_ans = sum(nums[l:a]) + sum(nums[b + 1:r + 1])
            ans = max(ans, cur_ans)
    return ans

def test_max_sum(nums):
    if not nums: return 0
    n = len(nums)
    p1 = sum(nums)
    p2 = must_one_scroll(nums, 0, n - 1)
    p3 = float('-inf')
    for i in range(1, n):
        p3 = max(p3, must_one_scroll(nums, 0, i - 1) + must_one_scroll(nums, i, n - 1))
    return max(p1, p2, p3)

def random_array(n, v):
    return [random.randint(-v, v) for _ in range(random.randint(0, n))]

# ---------------------------------------------------------
# 测试运行
# ---------------------------------------------------------
if __name__ == "__main__":
    sol = Solution()
    N, V, TEST_TIME = 30, 100, 5000
    print("测试开始...")
    for _ in range(TEST_TIME):
        arr = random_array(N, V)
        ans1 = test_max_sum(arr)
        ans2 = sol.max_sum_magic_scroll(arr)
        if ans1 != ans2:
            print(f"出错了! 数组: {arr}")
            print(f"正确答案: {ans1}, 你的答案: {ans2}")
            break
    else:
        print("测试结束，恭喜你通过了！")