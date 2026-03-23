#include <bits/stdc++.h>
using namespace std;

int N, F;
int nums[100010];
double sum[100010];

bool check(double avg) {
  for (int i = 1; i <= N; ++i) {
    sum[i] = sum[i - 1] + (nums[i - 1] - avg);
  }

  double min_val = 0;
  for (int i = F; i <= N; ++i) {
    if (sum[i] - min_val >= 0) {
      return true;
    }
    min_val = min(min_val, sum[i - F + 1]);
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> F;
  double l = 0, r = 0;
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
    r = max(r, (double)nums[i]);
  }

  while (r - l > 1e-5) {
    double mid = l + (r - l) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  // l <= TrueAns <= r
  // l向下取整会小于最终答案，故用r
  cout << (int)(r * 1000) << endl;
}