#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
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
#define debug_arr(first, last) do { cerr << "["; bool _f = false; for (auto _it = (first); _it != (last); ++_it) { if (_f) cerr << ", "; cerr << *_it; _f = true; } cerr << "]" << endl; } while(0)
#define debugline() cerr << "--------------------" << endl

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

int n;

void solve() {
  cin >> n;
  vector<int> nums(n);
  for (int& x : nums) cin >> x;

  vector<int> mn_st, mx_st;
  int ans = 0;
  for (int r = 0; r < n; ++r) {
    while (!mn_st.empty() && nums[r] <= nums[mn_st.back()]) {
      mn_st.pop_back();
    }
    while (!mx_st.empty() && nums[r] >= nums[mx_st.back()]) {
      mx_st.pop_back();
    }
    if (!mn_st.empty()) {
      int k = mx_st.empty() ? -1 : mx_st.back();
      int j = upper_bound(all(mn_st), k) - mn_st.begin();
      if (j != sz(mn_st)) {
        int l = mn_st[j];
        ans = max(ans, r - l + 1);
      }
    }
    mn_st.push_back(r);
    mx_st.push_back(r);
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
