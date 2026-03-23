#include <bits/stdc++.h>
using namespace std;

int n, k;
int chosen;

void dfs(vector<int>& ans) {
  if (ans.size() == k) {
    for (int i = 0; i < k; ++i) {
      printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');
    }
    return;
  }

  for (int i = 1; i < n + 1; ++i) {
    if ((1 << i) & chosen) {
      continue;
    }
    ans.push_back(i);
    chosen |= (1 << i);
    dfs(ans);
    ans.pop_back();
    chosen ^= (1 << i);
  }
}

int main() {
  cin >> n >> k;

  vector<int> ans;
  ans.reserve(n);

  dfs(ans);
}