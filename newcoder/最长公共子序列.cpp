#include <bits/stdc++.h>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i < v.size() - 1) os << ", ";
  }
  os << "]";
  return os;
}
#define debug(x) cerr << #x << " = " << x << endl
#define debug_arr(a, n) do { cerr << #a << " = ["; for (int i = 0; i < (n); ++i) { if (i) cerr << ", "; cerr << (a)[i]; } cerr << "]" << endl; } while(0)
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debugline() cerr << "--------------------" << endl

const int MAXN = 5005;
string s1, s2, ans;
int f[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s1[i] == s2[j]) {
        f[i + 1][j + 1] = f[i][j] + 1;
      } else {
        f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
      }
    }
  }

  if (f[n][m] == 0) {
    cout << -1 << endl;
    return 0;
  }
  int cnt = f[n][m];
  string ans;
  int i = n, j = m;
  while (cnt > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      ans.push_back(s1[i - 1]);
      --i; --j; --cnt;
    } else {
      f[i - 1][j] >= f[i][j - 1] ? --i : --j;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}