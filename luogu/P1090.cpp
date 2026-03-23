#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << "}"; }
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debug_arr(a, n) do { cerr << #a << " = ["; for (int i = 0; i < (n); ++i) { if (i) cerr << ", "; cerr << (a)[i]; } cerr << "]" << endl; } while(0)
#define debugline() cerr << "--------------------" << endl

int n;
priority_queue<int, vector<int>, greater<int>> mn;

void solve() {
  cin >> n;
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    mn.push(x);
  }
  int ans = 0;
  while (1) {
    int a = mn.top();
    mn.pop();
    int b = mn.top();
    mn.pop();
    ans += a + b;
    if (mn.empty()) {
      cout << ans << endl;
      return;
    } else {
      mn.push(a + b);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
