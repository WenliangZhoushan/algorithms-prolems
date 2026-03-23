#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define endl "\n"
#define long long ll
#define fi first
#define se second

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

int t;
string x;
int nums[100];

void solve() {
  cin >> x;
  
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    nums[i] = x[i] - '0';
  }

  sort(nums + 1, nums + n);
  int ans0 = 1, ans1 = 0;
  int s0 = nums[0], s1 = 1;
  for (int i = 1; i < n; ++i) {
    if (s0 + nums[i] <= 9) {
      ++ans0;
      s0 += nums[i];
    } else {
      break;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (s1 + nums[i] <= 9) {
      ++ans1;
      s1 += nums[i];
    } else {
      break;
    }
  }
  cout << n - max(ans0, ans1) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;
  while (t--) {
    solve();
  }
}