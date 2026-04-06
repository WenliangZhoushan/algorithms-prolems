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

const int maxn = 2e5 + 5;
int t;
int n, m, q;
int a;
int pos[maxn];

void solve() {
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) cin >> pos[i];
  sort(pos + 1, pos + m + 1);

  while (q--) {
    cin >> a;
    int i = lower_bound(pos + 1, pos + m + 1, a) - pos;
    if (i == 1) {
      cout << pos[i] - 1 << endl;
    } else if (i == m + 1) {
      cout << n - pos[i - 1] << endl;
    } else {
      cout << (pos[i] - pos[i - 1]) / 2 << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    solve();
  }
}
