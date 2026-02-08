"""
非负数组前k个最小的子序列累加和
给定一个数组nums，含有n个数字，都是非负数
给定一个正数k，返回所有子序列中累加和最小的前k个累加和
子序列是包含空集的
1 <= n <= 10^5
1 <= nums[i] <= 10^6
1 <= k <= 10^5
注意这个数据量，用01背包的解法是不行的，时间复杂度太高了
"""

import heapq
import random

class Solution:
    # 正式方法：堆优化
    # 时间复杂度 O(n * log n) + O(k * log k)
    def topKSum3(self, nums: list[int], k: int) -> list[int]:
        nums.sort()
        ans = [0] * k
        if not nums:
            return ans
        
        # (当前累加和, 当前指向的数组下标)
        # 初始放入最小的非空子序列：nums[0]
        min_heap = [(nums[0], 0)]
        
        # ans[0] 已经是 0 (空集)，所以从 1 开始填
        for i in range(1, k):
            cur_sum, right = heapq.heappop(min_heap)
            ans[i] = cur_sum
            
            if right + 1 < len(nums):
                # 策略1: 替换当前元素为下一个更长的元素
                heapq.heappush(min_heap, (cur_sum - nums[right] + nums[right + 1], right + 1))
                # 策略2: 保留当前元素并加上下一个元素
                heapq.heappush(min_heap, (cur_sum + nums[right + 1], right + 1))
        
        return ans

    # 暴力方法：递归得到所有子序列和
    def topKSum1(self, nums: list[int], k: int) -> list[int]:
        all_sums = []
        
        def f(index, current_sum):
            if index == len(nums):
                all_sums.append(current_sum)
            else:
                f(index + 1, current_sum)
                f(index + 1, current_sum + nums[index])
        
        f(0, 0)
        all_sums.sort()
        return all_sums[:k]

    # 01背包方法
    def topKSum2(self, nums: list[int], k: int) -> list[int]:
        total_sum = sum(nums)
        # dp[j] 表示累加和为 j 的子序列个数
        dp = [0] * (total_sum + 1)
        dp[0] = 1
        
        for num in nums:
            for j in range(total_sum, num - 1, -1):
                dp[j] += dp[j - num]
        
        ans = []
        count = 0
        for j in range(total_sum + 1):
            if count >= k:
                break
            for _ in range(dp[j]):
                if count < k:
                    ans.append(j)
                    count += 1
                else:
                    break
        return ans

# --- 对数器逻辑 ---

def random_array(n, v):
    return [random.randint(0, v) for _ in range(n)]

def test():
    sol = Solution()
    n = 12        # 数组长度不宜过大，否则暴力方法会超时/超内存
    v = 30        # 数值范围
    test_time = 1000
    print("测试开始")
    
    for i in range(test_time):
        length = random.randint(1, n)
        nums = random_array(length, v)
        # k 不能超过子序列总数 2^length
        k = random.randint(1, 1 << length)
        
        ans1 = sol.topKSum1(nums, k)
        ans2 = sol.topKSum2(nums, k)
        ans3 = sol.topKSum3(nums, k)
        
        if ans1 != ans2 or ans1 != ans3:
            print(f"出错了！")
            print(f"nums: {nums}, k: {k}")
            print(f"ans1: {ans1}")
            print(f"ans2: {ans2}")
            print(f"ans3: {ans3}")
            break
    else:
        print("测试结束，没有发现错误。")

if __name__ == "__main__":
    test()