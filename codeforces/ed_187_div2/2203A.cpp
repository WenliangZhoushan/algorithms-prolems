#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define endl "\n"
#define long long ll
#define fi first
#define se second

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i < v.size() - 1) os << ", ";
  }
  os << "]";
  return os;
}
#define debug(x) cerr << #x << " = " << x << endl
#define debug_arr(a, n) do { cerr << #a << " = ["; for (int i = 0; i < (n); ++i) { if (i) cerr << ", "; cerr << (a)[i]; } cerr << "]" << endl; } while(0)
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debugline() cerr << "--------------------" << endl

int t;
int n, m, d;

void solve() {
  cin >> n >> m >> d;
  int x = d / m + 1;
  cout << (n + x - 1) / x << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;
  while (t--) {
    solve();
  }
}