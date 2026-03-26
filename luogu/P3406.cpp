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
#define line() cerr << "--------------------" << endl

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

int n, m;

void solve() {
  cin >> n >> m;
  vector<int> nums(m);
  for (int& x : nums) cin >> x;
  vector prices(n - 1, vector<int>(3));
  for (auto& x : prices) {
    for (int& p : x) cin >> p;
  }

  vector<int> f(n + 1);
  for (int i = 0; i < m - 1; ++i) {
    int x, y;
    if (nums[i] < nums[i + 1]) {
      x = nums[i], y = nums[i + 1];
    } else {
      x = nums[i + 1], y = nums[i];
    }
    ++f[x];
    --f[y];
  }

  for (int i = 1; i <= n; ++i) f[i] += f[i - 1];
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    ll a = prices[i - 1][0], b = prices[i - 1][1], c = prices[i - 1][2];
    int t = f[i];
    if (a * t <= c + b * t) {
      ans += a * t;
    } else {
      ans += c + b * t;
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
