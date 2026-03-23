#include <bits/stdc++.h>
using namespace std;

int n, k;
int nums[4];

void dfs(vector<int>& ans) {
  if (ans.size() == n) {
    for (int i = 0; i < n; ++i) {
      printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return;
  }

  for (int i = 0; i < k; ++i) {
    ans.push_back(nums[i]);
    dfs(ans);
    ans.pop_back();
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1; i < 5; ++i) nums[i - 1] = i;

  vector<int> ans;
  dfs(ans);
}