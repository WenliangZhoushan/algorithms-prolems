#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
int t, n;
int nums[MAXN];

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums, nums + n);
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n - 2; ++i) {
    int a = nums[i], b = nums[i + 1], c = nums[i + 2];
    int ans1 = c + b - 2 * a;
    int ans2 = b - a + c - b;
    int ans3 = c - b + c - a;
    ans = min({ans, ans1, ans2, ans3});
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}