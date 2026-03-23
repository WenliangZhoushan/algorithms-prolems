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

int t;
ll s, m;

int check(ll mid) {
  ll rem = s;
  for (int i = 62; i >= 0; --i) {
    if ((m >> i) & 1) {
      ll a = 1LL << i;
      ll b = min(mid, rem / a);
      rem -= a * b;
    }
  }
  return rem == 0;
}

void solve() {
  cin >> s >> m;

  ll lowbit = m & (~m + 1);
  if (s % lowbit != 0) {
    cout << -1 << endl;
    return;
  }
  ll l = 1, r = s / lowbit;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (!check(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    solve();
  }
}