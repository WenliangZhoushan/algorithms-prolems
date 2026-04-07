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

const int maxn = 1e5 + 5;
int n;
int h1[maxn], h2[maxn];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h1[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> h2[i];
  }

  ll cnt1 = 0, cnt2 = 0;
  ll a = 0, b = 0;
  for (int i = 1; i <= n; ++i) {
    a = cnt2 + h1[i], b = cnt1 + h2[i];
    cnt1 = max(cnt1, a), cnt2 = max(cnt2, b);
  }

  cout << max(cnt1, cnt2) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
