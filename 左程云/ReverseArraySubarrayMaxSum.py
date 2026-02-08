import random
random.seed(42)
import sys
import math

# // 可以翻转1次的情况下子数组最大累加和
# // 给定一个数组nums，
# // 现在允许你随意选择数组连续一段进行翻转，也就是子数组逆序的调整
# // 比如翻转[1,2,3,4,5,6]的[2~4]范围，得到的是[1,2,5,4,3,6]
# // 返回必须随意翻转1次之后，子数组的最大累加和
# // 对数器验证

class Solution:
    def maxSumReverse(self, nums: list[int]) -> int:
        n = len(nums)
        f1 = [0] * n
        f1[0] = nums[0]

        for i in range(1, n):
            f1[i] = max(f1[i - 1] + nums[i], nums[i])

        f2 = [0] * n
        f2[-1] = nums[-1]

        for j in range(n - 2, -1, -1):
            f2[j] = max(f2[j + 1] + nums[j], nums[j])

        ans = -math.inf
        pre = f1[0]
        for i in range(1, n):
            ans = max(pre + f2[i], ans)
            pre = max(pre, f1[i])

        return max(ans, max(f1))

# --- 对数器验证部分 ---

def max_sum_reverse_brute(nums: list[int]) -> int:
    """
    暴力方法：用于对数器验证
    """
    def get_max_sum(arr):
        if not arr:
            return 0
        ans = arr[0]
        pre = arr[0]
        for i in range(1, len(arr)):
            pre = max(arr[i], pre + arr[i])
            ans = max(ans, pre)
        return ans

    ans = -sys.maxsize
    n = len(nums)
    # 枚举所有可能的左右边界 [l, r]
    for l in range(n):
        for r in range(l, n):
            # 翻转子数组
            copy_nums = nums[:]
            copy_nums[l:r+1] = copy_nums[l:r+1][::-1]
            ans = max(ans, get_max_sum(copy_nums))
    return ans

def generate_random_array(n, v):
    return [random.randint(-v, v) for _ in range(random.randint(1, n))]

def validator():
    test_time = 2000
    max_len = 30
    max_value = 100
    sol = Solution()
    
    print("测试开始")
    for i in range(test_time):
        arr = generate_random_array(max_len, max_value)
        ans1 = max_sum_reverse_brute(arr)
        ans2 = sol.maxSumReverse(arr)
        if ans1 != ans2:
            print(f"出错了！数组：{arr}")
            print(f"预期结果: {ans1}, 实际结果: {ans2}")
            return
    print("测试结束，通过！")

if __name__ == "__main__":
    validator()