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

const int MAXN = 1e7 + 10;
int n, m;
int l, r, s, e;
ll diff[MAXN];

void solve() {
  memset(diff, 0, MAXN);

  scanf("%d%d", &n, &m);
  int c;
  while (m--) {
    scanf("%d%d%d%d", &l, &r, &s, &e);
    c = (e - s) / (r - l);
    diff[l] += s;
    diff[l + 1] += -s + c;
    diff[r + 1] -= c + e;
    diff[r + 2] += e;
  }
  for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1];
  for (int i = 1; i <= n; ++i) diff[i] += diff[i - 1];
  ll mx = NEG_INF, s = 0;
  for (int i = 1; i <= n; ++i) {
    s ^= diff[i];
    mx = max(diff[i], mx);
  }
  cout << s << " " << mx << endl;
}


int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  solve();
}
