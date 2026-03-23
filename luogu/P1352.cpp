#include <bits/stdc++.h>
using namespace std;

struct edge{
  int to, nxt;
};
int heads[6010];
edge edges[6010];
int ins[6010];
int cnt = 1;
int rewards[6010];
int n;

int memo[6010][2];


// j 代表 i 的上司来没来
// int dfs(int i, int j) {
//     int&ans = memo[i][j];
//     if (ans != 0xcfcfcfcf) {
//         return ans;
//     }
//     if (j) {
//         int ans = 0;
//         for (int k = heads[i]; k != 0; k = edges[k].nxt) {
//             ans += dfs(edges[k].to, 0);
//         }
//         return ans;
//     } else {
//         int cnt0 = 0, cnt1 = rewards[i];
//         for (int k = heads[i]; k != 0; k = edges[k].nxt) {
//             cnt0 += dfs(edges[k].to, 0);
//             cnt1 += dfs(edges[k].to, 1);
//         }
//         ans = max(cnt0, cnt1);
//         return ans;
//     }
// }


// j 代表 i 是否参加了舞会
int dfs(int i, int j) {
  int&ans = memo[i][j];
  if (ans != 0xcfcfcfcf) {
    return ans;
  }
  if (j) {
    ans = rewards[i];
    for (int k = heads[i]; k != 0; k = edges[k].nxt) {
      ans += dfs(edges[k].to, 0);
    }
    return ans;
  } else {
    ans = 0;
    for (int k = heads[i]; k != 0; k = edges[k].nxt) {
      ans += max(dfs(edges[k].to, 0), dfs(edges[k].to, 1));
    }
    return ans;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i < n + 1; ++i) {
    cin >> rewards[i];
  }
  for (int i = 1; i < n; ++i) {
    int l, k; // k -> l
    cin >> l >> k;
    struct edge e;
    e.to = l;
    e.nxt = heads[k];
    heads[k] = cnt;
    edges[cnt++] = e;
    ++ins[l];
  }

  memset(memo, 0xcf, sizeof(memo));
  for (int i = 1; i < n + 1; ++i) {
    if (ins[i] == 0) {
      cout << max(dfs(i, 0), dfs(i, 1)) << endl;
      return 0;
    }
  }
}