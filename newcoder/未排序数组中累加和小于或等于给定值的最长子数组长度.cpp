// https://www.nowcoder.com/practice/3473e545d6924077a4f7cbc850408ade

// 给定一个无序数组arr，其中元素可正、可负、可0。给定一个整数k，求arr所有的子数组中累加和小于或等于k的最长子数组长度
// 例如：arr = [3, -2, -4, 0, 6], k = -2. 相加和小于等于-2的最长子数组为{3, -2, -4, 0}，所以结果返回4

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

int N, k;
int nums[100010];
int s[100010];
int st[100010];
int f[100010];

int solve() {
  for (int i = 1; i < N + 1; ++i) {
    int x = s[i] - k;
    int l = 0, r = i - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (st[m] < x) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    f[i - 1] = i - l;
  }
  // debug_arr(f, N);
  return *max_element(f, f + N);
}

int main() {
  cin >> N >> k;
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
    s[i + 1] = s[i] + nums[i];
    st[i + 1] = max(st[i], s[i + 1]);
  }
  // debug_arr(nums, N);
  // debug_arr(s, N);
  // debug_arr(st, N);
  // debugline();

  cout << solve() << endl;
}
