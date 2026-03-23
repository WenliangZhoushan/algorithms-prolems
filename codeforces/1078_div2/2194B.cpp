#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[200010];
int x, y;
long long cnt[200010];

void solve(int n, int x, int y) {
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[i] = a[i] / x * y;
    s += cnt[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, s - cnt[i] + a[i]);
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> x >> y;
    solve(n, x, y);
  }
}