n = int(input())
nums = list(map(int, input().split()))

mx = 0
for i, x in enumerate(nums):
    if i > mx:
        break
    mx = max(mx, i + x - 1)

print(min(mx + 1, n))
