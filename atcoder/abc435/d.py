from collections import defaultdict

n, m = map(int, input().split())
cnt = [0] * (n + 1)
g = defaultdict(list)
for _ in range(m):
    a, b = map(int, input().split())
    g[b].append(a)

def bfs(i):
    if cnt[i] == 1:
        return
    cnt[i] = 1
    q = [i]
    while q:
        nxt = []
        for b in q:
            for a in g[b]:
                if cnt[a] != 1:
                    cnt[a] = 1
                    nxt.append(a)
        q = nxt

Q = int(input())

for _ in range(Q):
    op, a = map(int, input().split())
    if op == 1:
        bfs(a)
    else:
        print('Yes' if cnt[a] == 1 else 'No')
