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

const int maxn = 1e3 + 5;
int t, n, m;
string s, a = "narek";
int f[maxn][5];

pii score(string b, int j) {
  int ans = 0;
  for (char c : b) {
    if (c == a[j]) {
      ++j;
      if (j == 5) {
        ans += 9;
        j = 0;
        continue;
      }
    }
    if (a.find(c) != string::npos) --ans;
  }

  return {j, ans};
}

void solve() {
  cin >> n >> m;
  memset(f, NEG_INF, sizeof(f));
  f[0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 0; j < 5; ++j) {
      f[i][j] = f[i - 1][j];
    }
    for (int j = 0; j < 5; ++j) {
      auto [nxt, cnt] = score(s, j);
      f[i][nxt] = max(f[i][nxt], f[i - 1][j] + cnt);
    }
  }

  int ans = 0;
  for (int j = 0; j < 5; ++j) ans = max(ans, f[n][j]);

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    solve();
  }
}
