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

const int MAXN = 200005;
int t, n;
ll nums[MAXN];
int cnt[MAXN];

void solve() {
  fill(cnt, cnt + MAXN, 0);

  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> nums[i];
  }
  int x = -1;
  for (int i = 1; i <= n - 1; ++i) {
    ll a = nums[i] - nums[i - 1];
    if (a > n + n - 1) {
      cout << "NO" << endl;
      return;
    }
    if (a > n || cnt[a] == 1) {
      if (x != -1) {
        // debug_arr(nums + 1, n - 1);
        // debug2(i, x);
        // debug_arr(cnt + 1, n);
        cout << "NO" << endl;
        return;
      } else {
        x = a;
      }
    } else {
      cnt[a] = 1;
    }
  }
  if (x == -1) {
    cout << "YES" << endl;
    return;
  }
  int a, b;
  for (int i = 1; i <= n; ++i) {
    if (!cnt[i]) {
      a = i;
      break;
    }
  }
  for (int j = n; j > a; --j) {
    if (!cnt[j]) {
      b = j;
      break;
    }
  }
  if (a + b == x) {
    cout << "YES" << endl;
  } else {
    // debug3(x, a, b);
    // debug_arr(cnt + 1, n);
    cout << "NO" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    solve();
    // line();
  }
}
