#include <bits/stdc++.h>
using namespace std;

int t;
int n, w;

void solve(int n, int w) {
  int ans = 0;
  ans += n / w * (w - 1);
  ans += n % w;
  cout << ans << endl;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> w;
    solve(n, w);
  }
}