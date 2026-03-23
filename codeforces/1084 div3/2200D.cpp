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

int t, n, x, y;
int nums[200005];

void solve() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
  }

  vector<int> s, b;
  for (int i = 1; i <= x; ++i) s.push_back(nums[i]);
  for (int i = y + 1; i <= n; ++i) s.push_back(nums[i]);

  int i = x + 1;
  for (int j = x + 1; j <= y; ++j) {
    if (nums[j] < nums[i]) i = j;
  }
  for (int j = i; j <= y; ++j) b.push_back(nums[j]);
  for (int j = x + 1; j < i; ++j) b.push_back(nums[j]);

  if (s.empty()) {
    for (int i = 0; i < sz(b); ++i) {
      cout << b[i] << " \n"[i == sz(b) - 1];
    }
    return;
  } else {
    int i = sz(s);
    for (int j = 0; j < sz(s); ++j) {
      if (s[j] > b[0]) {
        i = j;
        break;
      }
    }
    for (int j = 0; j < i; ++j) cout << s[j] << " ";
    for (auto& x : b) cout << x << " ";
    for (int j = i; j < sz(s); ++j) cout << s[j] << " ";
    cout << endl;
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
