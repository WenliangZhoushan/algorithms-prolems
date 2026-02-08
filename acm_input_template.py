"""
Python ACM 输入处理模板 - 精简版
"""

import sys

# ============================================================================
# 一、基础输入
# ============================================================================

# 1. 单个整数
n = int(input())

# 2. 单行多个整数
a, b = map(int, input().split())
a, b, c = map(int, input().split())

# 3. 单行整数数组
arr = list(map(int, input().split()))

# 4. 字符串（去除首尾空白）
s = input().strip()

# 5. 多个字符串
str1, str2 = input().split()

# 6. 字符数组
chars = list(input().strip())


# ============================================================================
# 二、多行输入
# ============================================================================

# 1. 读取n行数字
n = int(input())
data = []
for _ in range(n):
    data.append(int(input()))

# 或者用列表推导式（推荐）
data = [int(input()) for _ in range(n)]

# 2. 读取n行数组
n = int(input())
arrays = []
for _ in range(n):
    arr = list(map(int, input().split()))
    arrays.append(arr)

# 3. 读取矩阵（n行m列）
n, m = map(int, input().split())
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

# 列表推导式版本
matrix = [list(map(int, input().split())) for _ in range(n)]

# 4. 字符矩阵（网格）
n, m = map(int, input().split())
grid = [list(input().strip()) for _ in range(n)]


# ============================================================================
# 三、多组测试用例
# ============================================================================

# 方式1：已知测试组数
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    # 处理并输出
    print(sum(arr))

# 方式2：读到EOF
try:
    while True:
        n = int(input())
        # 处理数据
except EOFError:
    pass

# 方式3：输入0结束
while True:
    n = int(input())
    if n == 0:
        break
    # 处理数据

# 方式4：sys.stdin逐行读取
for line in sys.stdin:
    n = int(line.strip())
    # 处理数据


# ============================================================================
# 四、图论输入
# ============================================================================

# 1. 无权图邻接表
n, m = map(int, input().split())  # n个节点，m条边
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)  # 无向图

# 2. 带权图邻接表
n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))  # 无向图

# 3. 邻接矩阵
n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]


# ============================================================================
# 五、特殊格式
# ============================================================================

# 1. 坐标点
n = int(input())
points = []
for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))

# 2. 区间
n = int(input())
intervals = [(int(x), int(y)) for x, y in [input().split() for _ in range(n)]]

# 3. 树的边（n个节点，n-1条边）
n = int(input())
edges = []
for _ in range(n - 1):
    u, v = map(int, input().split())
    edges.append((u, v))


# ============================================================================
# 六、快速IO（大数据量）
# ============================================================================

import sys
input = sys.stdin.readline  # 替换掉默认的input

n = int(input())
arr = list(map(int, input().split()))

# 批量输出
results = []
t = int(input())
for _ in range(t):
    # 计算
    results.append(str(result))
print('\n'.join(results))


# ============================================================================
# 七、常用竞赛模板
# ============================================================================

# 模板1：单组数据
n = int(input())
arr = list(map(int, input().split()))
# 算法处理
result = sum(arr)
print(result)

# 模板2：多组数据
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    # 算法处理
    result = max(arr)
    print(result)

# 模板3：快速IO版本
import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    # 算法实现
    return sum(arr)

t = int(input())
for _ in range(t):
    print(solve())


# ============================================================================
# 注意事项
# ============================================================================
"""
1. 大数据量用 sys.stdin.readline 替换 input()
2. 字符串记得用 strip() 去除空白
3. 批量输出用列表收集再一次性print，减少IO
4. 矩阵/数组用列表推导式更简洁
5. 本地测试：python solution.py < input.txt > output.txt
"""
