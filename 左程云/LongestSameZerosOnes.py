from typing import List
import random

'''
// 两个0和1数量相等区间的最大长度
// 给出一个长度为n的01串，现在请你找到两个区间
// 使得这两个区间中，1的个数相等，0的个数也相等
// 这两个区间可以相交，但是不可以完全重叠，即两个区间的左右端点不可以完全一样
// 现在请你找到两个最长的区间，满足以上要求
// 返回区间最大长度
// 来自真实大厂笔试，没有在线测试，对数器验证
'''

class Solution:
    def longest_same_zeros_ones(self, arr: List[int]) -> int:
        l0 = r0 = l1 = r1 = -1
        for i, x in enumerate(arr):
            if x == 0 and l0 == -1:
                l0 = i
            if x == 1 and l1 == -1:
                l1 = i
        for i in range(len(arr) - 1, -1, -1):
            if arr[i] == 0 and r0 == -1:
                r0 = i
            if arr[i] == 1 and r1 == -1:
                r1 = i
        return max(r0 - l0, r1 - l1)

def brute_force(arr: List[int]) -> int:
    """
    暴力方法：用于对数器验证
    使用哈希表记录 (0的个数, 1的个数) 出现的次数
    """
    n = len(arr)
    counts = {}
    
    # 遍历所有可能的区间
    for i in range(n):
        zeros = 0
        ones = 0
        for j in range(i, n):
            if arr[j] == 0:
                zeros += 1
            else:
                ones += 1
            
            pair = (zeros, ones)
            counts[pair] = counts.get(pair, 0) + 1
            
    ans = 0
    for (zeros, ones), num in counts.items():
        if num > 1: # 如果同样的(0,1)组合出现超过1次，说明存在两个不同的区间
            ans = max(ans, zeros + ones)
    return ans

# --- 对数器测试部分 ---
def generate_random_array(max_len):
    length = random.randint(2, max_len)
    return [random.randint(0, 1) for _ in range(length)]

if __name__ == "__main__":
    sol = Solution()
    test_times = 1000
    max_length = 100
    print("测试开始...")
    for i in range(test_times):
        arr = generate_random_array(max_length)
        ans1 = brute_force(arr)
        ans2 = sol.longest_same_zeros_ones(arr)
        if ans1 != ans2:
            print(f"出错了！数组: {arr}")
            print(f"暴力解: {ans1}, 你的解: {ans2}")
            break
        if (i + 1) % 100 == 0:
            print(f"已测试 {i + 1} 组数据")
    else:
        print("测试结束，全部通过！")
