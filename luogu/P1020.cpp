#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<int> nums;
  int x;

  string line;
  getline(cin, line);
  stringstream ss(line);
  while (ss >> x) {
    nums.push_back(x);
  }

  int n = nums.size();
  vector<int> f;

  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      f.push_back(nums[i]);
      continue;
    }
    int lo = 0, hi = f.size() - 1;
    while (lo <= hi) {
      int m = lo + (hi - lo) / 2;
      if (f[m] >= nums[i]) {
        lo = m + 1;
      } else {
        hi = m - 1;
      }
    }
    if (lo == f.size()) {
      f.push_back(nums[i]);
      continue;
    } else {
      f[lo] = max(f[lo], nums[i]);
    }
  }

  int ans1 = f.size(), ans2;
  f.clear();

  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      f.push_back(nums[i]);
      continue;
    }
    int lo = 0, hi = f.size() - 1;
    while (lo <= hi) {
      int m = lo + (hi - lo) / 2;
      if (f[m] < nums[i]) {
        lo = m + 1;
      } else {
        hi = m - 1;
      }
    }
    if (lo == f.size()) {
      f.push_back(nums[i]);
      continue;
    }
    f[lo] = nums[i];
  }
  ans2 = f.size();

  cout << ans1 << endl;
  cout << ans2 << endl;
}