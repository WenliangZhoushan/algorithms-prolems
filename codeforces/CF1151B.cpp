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

const int MAXN = 505;
int n, m;
int nums[MAXN][MAXN];

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> nums[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) cnt ^= nums[i][0];
  vector<int> ans(n, 1);
  if (cnt == 0) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (nums[i][j] != nums[i][0]) {
          ans[i] = j + 1;
          cout << "TAK" << endl;
          for (int k = 0; k < n; ++k) {
            cout << ans[k] << " \n"[k == n - 1];
          }
          return;
        }
      }
    }
  } else {
    cout << "TAK" << endl;
    for (int k = 0; k < n; ++k) {
      cout << ans[k] << " \n"[k == n - 1];
    }
    return;
  }
  cout << "NIE" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
