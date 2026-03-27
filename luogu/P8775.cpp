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

const int MAXN = 1e5 + 5;
int n, x;
int nums[MAXN], s[MAXN];

int check(int m) {
  for (int i = m; i < n; ++i) {
    if (s[i] - s[i - m] < 2 * x) {
      return 0;
    }
  }
  return 1;
}

void solve() {
  cin >> n >> x;
  for (int i = 1; i < n; ++i) {
    cin >> nums[i];
    s[i] = nums[i] + s[i - 1];
  }

  int l = 1, r = n;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (check(m)) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << r + 1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}
