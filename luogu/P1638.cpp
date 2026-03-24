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

const int MAXN = 1e6 + 10;
int n, m;
int nums[MAXN];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> nums[i];
  int ans_l = 0, ans_r = n + 1;
  unordered_map<int, int> cnt;
  int l = 1;
  for (int r = 1; r <= n; ++r) {
    ++cnt[nums[r]];
    while (sz(cnt) == m) {
      if (r - l < ans_r - ans_l) {
        ans_l = l, ans_r = r;
      }
      --cnt[nums[l]];
      if (cnt[nums[l]] == 0) cnt.erase(nums[l]);
      ++l;
    }
  }
  cout << ans_l << " " << ans_r << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
