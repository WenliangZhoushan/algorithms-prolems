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

int const MAXN = 100005;
int n;
int mod = 1'000'000'007;
int pow2[MAXN];

void solve() {
  cin >> n;
  vector<int> cnt(MAXN);
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ++cnt[x];
  }
  vector<int> f(MAXN);

  for (int i = 100000; i >= 1; --i) {
    int s = 0;
    for (int j = i; j < MAXN; j += i) s += cnt[j];
    f[i] = (pow2[s] - 1 + mod) % mod;
    for (int j = 2 * i; j < MAXN; j += i) {
      f[i] = (f[i] - f[j] + mod) % mod;
    }
  }

  cout << f[1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pow2[0] = 1;
  for (int i = 1; i <= MAXN; ++i) {
    pow2[i] = (pow2[i - 1] * 2) % mod;
  }

  solve();
}
