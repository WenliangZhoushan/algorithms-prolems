import sys

n = int(input())
nums = list(map(int, input().split()))

s = [0]
for i, x in enumerate(nums):
    s.append(s[-1] + x)
ans = 0

for l in range(n): 
    for r in range(l + 1, n): 
        flag = True 
        for i in range(l, r + 1): 
            if (s[r + 1] - s[l]) % nums[i] == 0: 
                flag = False 
                break 
        ans += int(flag) 
        
print(ans)
