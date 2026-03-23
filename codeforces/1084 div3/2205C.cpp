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

int t, n;
void solve() {
  cin >> n;
  vector<vector<int>> nums(n);
  unordered_set<int> seen;
  int m;
  
  for (int i = 0; i < n; ++i) {
    cin >> m;
    vector<int> temp(m);
    for (int j = 0; j < m; ++j) {
      cin >> temp[j];
    }
    reverse(all(temp));
    
    seen.clear();
    for (int x : temp) {
      if (seen.contains(x)) continue;
      seen.insert(x);
      nums[i].push_back(x);
    }
  }
  seen.clear();
  if (n == 1) {
    for (int& x : nums[0]) cout << x << " ";
    cout << endl;
    return;
  }
  
  vector<int> ans;
  unordered_set<int> cnt;
  
  for (int step = 0; step < n; ++step) {
    int a = -1;
    for (int j = 0; j < n; ++j) {
      if (cnt.contains(j)) continue;
      if (a == -1 || nums[j] < nums[a]) {
        a = j;
      }
    }
    cnt.insert(a);
    for (int x : nums[a]) {
      if (!seen.contains(x)) {
        ans.push_back(x);
        seen.insert(x);
      }
    }
    
    for (int i = 0; i < n; ++i) {
      if (cnt.contains(i)) continue;
      vector<int> nxt;
      for (int x : nums[i]) {
        if (!seen.contains(x)) {
          nxt.push_back(x);
        }
      }
      nums[i] = nxt;
    }
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  while (t--) {
    solve();
  }
}