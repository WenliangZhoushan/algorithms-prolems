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

int a, b, n;

void solve() {
  cin >> a >> b >> n;
  vector nums(a, vector<int>(b));
  for (auto& row : nums) {
    for (int& x : row) cin >> x;
  }

  vector cnt(b, vector<deque<int>>(2));
  for (int j = 0; j < b; ++j) {
    deque<int> &mnq = cnt[j][0], &mxq = cnt[j][1];
    for (int i = 0; i < n - 1; ++i) {
      while (!mnq.empty() && nums[i][j] <= nums[mnq.back()][j]) mnq.pop_back();
      mnq.push_back(i);
      while (!mxq.empty() && nums[i][j] >= nums[mxq.back()][j]) mxq.pop_back();
      mxq.push_back(i);
    }
  }

  int ans = INF;

  for (int i = 0; i <= a - n; ++i) {
    deque<pii> r_mnq, r_mxq;
    for (int j = 0; j < b; ++j) {
      deque<int> &c_mnq = cnt[j][0], &c_mxq = cnt[j][1];
      while (!c_mnq.empty() && c_mnq.front() < i) c_mnq.pop_front();
      while (!c_mnq.empty() && nums[i + n - 1][j] <= nums[c_mnq.back()][j]) c_mnq.pop_back();
      c_mnq.push_back(i + n - 1);
      while (!c_mxq.empty() && c_mxq.front() < i) c_mxq.pop_front();
      while (!c_mxq.empty() && nums[i + n - 1][j] >= nums[c_mxq.back()][j]) c_mxq.pop_back();
      c_mxq.push_back(i + n - 1);

      while (!r_mnq.empty() && r_mnq.front().se < j - n + 1) r_mnq.pop_front();
      while (!r_mnq.empty() && nums[c_mnq.front()][j] <= nums[r_mnq.back().fi][r_mnq.back().se]) r_mnq.pop_back();
      r_mnq.emplace_back(c_mnq.front(), j);
      while (!r_mxq.empty() && r_mxq.front().se < j - n + 1) r_mxq.pop_front();
      while (!r_mxq.empty() && nums[c_mxq.front()][j] >= nums[r_mxq.back().fi][r_mxq.back().se]) r_mxq.pop_back();
      r_mxq.emplace_back(c_mxq.front(), j);

      if (j >= n - 1) {
        ans = min(ans, nums[r_mxq.front().fi][r_mxq.front().se] - nums[r_mnq.front().fi][r_mnq.front().se]);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}