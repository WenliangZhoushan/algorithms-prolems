import collections
import random
random.seed(42)

# // 删掉1个数字后长度为k的子数组最大累加和
# // 给定一个数组nums，求必须删除一个数字后的新数组中
# // 长度为k的子数组最大累加和，删除哪个数字随意
# // 对数器验证

class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        if k >= len(nums):
            return 0
        q = collections.deque()
        ans = float("-inf")
        cnt = 0
        k += 1

        for i, x in enumerate(nums):
            if i < k - 1:
                cnt += x
                while q and x <= q[-1][0]:
                    q.pop()
                q.append((x, i))
                continue
            while q and i - q[0][1] >= k:
                q.popleft()
            while q and x <= q[-1][0]:
                q.pop()
            q.append((x, i))
            cnt += x
            ans = max(ans, cnt - q[0][0])
            cnt -= nums[i - k + 1]

        return ans

# --- 对数器验证部分 ---
import random

def len_k_max_sum(arr, k):
    if len(arr) < k:
        return float('-inf')
    res = float('-inf')
    for i in range(len(arr) - k + 1):
        res = max(res, sum(arr[i:i+k]))
    return res

def max_sum_brute_force(nums, k):
    n = len(nums)
    if n <= k:
        return 0
    ans = float('-inf')
    # 暴力枚举：尝试删除每一个位置的数
    for i in range(n):
        rest = nums[:i] + nums[i+1:]
        ans = max(ans, len_k_max_sum(rest, k))
    return int(ans)

def test():
    sol = Solution()
    n_limit = 50
    v_limit = 100
    test_times = 5000
    print("测试开始")
    for _ in range(test_times):
        n = random.randint(1, n_limit)
        k = random.randint(1, n_limit)
        nums = [random.randint(-v_limit, v_limit) for _ in range(n)]
        
        ans1 = max_sum_brute_force(nums, k)
        ans2 = sol.maxSum(nums, k)
        
        # 处理逻辑：如果 n <= k，根据原 Java 代码逻辑应返回 0
        if n <= k:
            ans1 = 0
            if ans2 is None: ans2 = 0 # 防止未实现返回None
            
        if ans1 != ans2:
            print(f"出错了! nums: {nums}, k: {k}")
            print(f"暴力解: {ans1}, 你的解: {ans2}")
            return
    print("测试结束，全部通过！")

if __name__ == "__main__":
    test()