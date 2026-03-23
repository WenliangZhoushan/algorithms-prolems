#include <bits/stdc++.h>
using namespace std;

int t, m;
long long f[10'000'010];

int main() {
  cin >> t >> m;
  vector<pair<int, int>> cv(m);

  for (int i = 0; i < m; ++i) {
    int c, v;
    cin >> c >> v;
    cv[i] = make_pair(c, v);
  }

  for (int i = 0; i < m; ++i) {
    auto& [c, v] = cv[i];
    for (int j = 0; j < t + 1; ++j) {
      if (j >= c) {
        f[j] = max(f[j], f[j - c] + v);
      }
    }
  }

  cout << f[t] << endl;

}