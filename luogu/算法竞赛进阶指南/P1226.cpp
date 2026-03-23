#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int p) {
  int ans = 1 % p; // p == 1, then ans = 0, regradless a & b, ans is always 0

  for (; b; b >>= 1) {
    if (b & 1) {
      ans = (long long)ans * a % p;
    }
    a = (long long) a * a % p;
  }

  return ans;
}

int main() {
  int a, b, p;
  cin >> a >> b >> p;

  int r = solve(a, b, p);

  stringstream ss;
  ss << a << "^" << b << " mod " << p << "=" << r;

  cout << ss.str() << endl;
}