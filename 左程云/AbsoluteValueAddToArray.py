import random
from typing import List

# TODO: 没做

# 加入差值绝对值直到长度固定
# 给定一个非负数组arr，计算任何两个数差值的绝对值
# 如果arr中没有，都要加入到arr里，但是只加一份
# 然后新的arr继续计算任何两个数差值的绝对值
# 如果arr中没有，都要加入到arr里，但是只加一份
# 一直到arr大小固定，返回arr最终的长度
#
# 例1: arr = [1, 3]
#   第1轮: |1-3|=2, 不在arr中 → 加入 → arr = [1, 3, 2]
#   第2轮: |1-3|=2✓ |1-2|=1✓ |3-2|=1✓ → 无新增
#   最终长度 = 3
#
# 例2: arr = [2, 8]
#   第1轮: |2-8|=6, 加入 → arr = [2, 8, 6]
#   第2轮: |2-6|=4, 加入 → arr = [2, 8, 6, 4]
#   第3轮: 所有差值 2,6,4,2,4,2 都已存在 → 无新增
#   最终长度 = 4
#   (观察: gcd=2, max=8, 最终就是 {2,4,6,8}, 即gcd的所有倍数直到max)
#
# 例3: arr = [3, 3, 6]
#   第1轮: |3-3|=0, 加入; |3-6|=3✓; |3-6|=3✓ → arr = [3, 3, 6, 0]
#   第2轮: 无新增
#   最终长度 = 4
#   (注意: 重复的3保留两份, 0也要占一个位置)
#
# 例4: arr = [0, 0, 0]
#   所有差值都是0, 已存在 → 无新增
#   最终长度 = 3

class Solution:
    # 暴力方法 - 为了验证
    def len1(self, arr: List[int]) -> int:
        lst = list(arr)
        st = set(arr)
        while True:
            old_len = len(lst)
            for i in range(old_len):
                for j in range(i + 1, old_len):
                    abs_val = abs(lst[i] - lst[j])
                    if abs_val not in st:
                        lst.append(abs_val)
                        st.add(abs_val)
            if len(lst) == old_len:
                break
        return len(lst)

    # 正式方法 - 时间复杂度O(n)
    def len2(self, arr: List[int]) -> int:
        # TODO: 自己实现
        pass


def main():
    N = 50
    V = 100
    test_times = 20000
    print("测试开始")
    sol = Solution()
    for _ in range(test_times):
        n = random.randint(1, N)
        nums = [random.randint(0, V - 1) for _ in range(n)]
        ans1 = sol.len1(nums)
        ans2 = sol.len2(nums)
        if ans1 != ans2:
            print(f"出错了！arr={nums}, 期望={ans1}, 实际={ans2}")
    print("测试结束")


if __name__ == "__main__":
    main()