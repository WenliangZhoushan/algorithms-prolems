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
#define debug_arr(first, last) do { cerr << "["; bool _f = false; for (auto _it = (first); _it != (last); ++_it) { if (_f) cerr << ", "; cerr << *_it; _f = true; } cerr << "]" << endl; } while(0)
#define debugline() cerr << "--------------------" << endl

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

const int MAXN = 3e4 + 10;
int n, m, q;
bitset<MAXN> f[MAXN];


void solve() {
  cin >> n >> m >> q;
  bitset<MAXN> bs;
  int c;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    int j;
    while (c--) {
      cin >> j;
      bs.set(j, 1);
    }
    f[i] = bs;
    bs.reset();
  }

  int op, x, y;
  for (int i = 0; i < q; ++i) {
    cin >> op >> x >> y;
    if (op == 1) {
      bs = f[x];
      bs <<= y;
      bitset<MAXN> mask;
      mask.set();
      mask >>= MAXN - m - 1;
      mask.set(0, 0);
      bs &= mask;
      f[x] = bs;
    } else if (op == 2) {
      bs = f[x];
      bs >>= y;
      bs.set(0, 0);
      f[x] = bs;
    } else if (op == 3) {
      cout << (f[x] & f[y]).count() << endl;
    } else if (op == 4) {
      cout << (f[x] | f[y]).count() << endl;
    } else {
      cout << (f[x] ^ f[y]).count() << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}
