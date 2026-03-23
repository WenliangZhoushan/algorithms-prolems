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

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

int t, n, k;
ll nums[2010];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
  }
  if (k >= 3) {
    cout << 0 << endl;
    return;
  }
  sort(nums + 1, nums + n + 1);
  ll mn = nums[1];
  for (int i = 1; i < n; ++i) {
    mn = min(mn, nums[i + 1] - nums[i]);
  }
  if (k == 1) {
    cout << mn << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ll diff = nums[j] - nums[i];
      auto it = lower_bound(nums + 1, nums + n + 1, diff);
      mn = min({mn, diff - *(it - 1), *it - diff});
    }
  }
  cout << mn << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    solve();
  }
}
