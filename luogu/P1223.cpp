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
const int MAXN = 1005;
int n;
pii nums[MAXN];

void solve() {
  cin >> n;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    nums[i] = make_pair(t, i);
  }
  sort(nums, nums + n, [](const auto& a, const auto& b){return a.fi == b.fi ? a.se < b.se : a.fi < b.fi;});
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    s += (n - i - 1) * nums[i].fi;
    cout << nums[i].se + 1 << " \n"[i == n - 1];
  }
  cout << fixed << setprecision(2) << (double) s / n << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
