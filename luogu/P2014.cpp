#include <bits/stdc++.h>
using namespace std;

int N, M;
int memo[310][310][310];
vector<int> g[310];
int scores[310];

// 当前来到i号节点为头的子树
// 只在i号节点、及其i号节点下方的前j棵子树上挑选节点
// 一共挑选k个节点，并且保证挑选的节点连成一片
// 返回最大的累加和
int dfs(int i, int j, int k) {
    if (k == 0) {
        return 0;
    }
    if (j == 0 || k == 1) {
        return scores[i];
    }
    if (memo[i][j][k] != -1) {
        return memo[i][j][k];
    }
    int& ans = memo[i][j][k];
    ans = dfs(i, j - 1, k); // 不选第j个子树
    int v = g[i][j - 1]; // v是第j个子树的头节点
    // 为什么不枚举所有子节点v呢？
    // 因为这是背包问题，背包问题对于某个物品，只有选或者不选
    for (int kk = 1; kk < k; ++kk) {
        ans = max(ans, dfs(i, j - 1, k - kk) + dfs(v, g[v].size(), kk));
    }
    return ans;
}

int main() {
    cin >> N >> M;
    int k, s;
    for (int i = 1; i < N + 1; ++i) {
        cin >> k >> s;
        g[k].push_back(i);
        scores[i] = s;
    }

    memset(memo, -1, sizeof(memo));

    // 应该选择M + 1门课，引入了一个收益为0的虚拟头节点
    cout << dfs(0, g[0].size(), M + 1) << endl;
}