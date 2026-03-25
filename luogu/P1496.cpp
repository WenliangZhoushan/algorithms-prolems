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

int n, a, b;

void solve() {
  cin >> n;
  vector<pii> q(n);
  vector<int> nums;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    q[i] = make_pair(a, b);
    nums.push_back(a);
    nums.push_back(b);
  }

  int mn = ranges::min(nums), mx = ranges::max(nums);
  sort(all(nums));
  auto it = unique(all(nums));
  int m = it - nums.begin();
  vector<int> f(m);

  for (auto [a, b] : q) {
    int i = lower_bound(nums.begin(), it, a) - nums.begin();
    int j = lower_bound(nums.begin(), it, b) - nums.begin();
    ++f[i];
    --f[j];
  }

  for (int i = 1; i < m; ++i) f[i] += f[i - 1];
  ll ans = 0;
  for (int i = 0; i < m; ++i) {
    if (f[i]) {
      int l = nums[i], r = nums[i + 1];
      ans += r - l;
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
