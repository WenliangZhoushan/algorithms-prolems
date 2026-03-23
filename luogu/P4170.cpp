#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

string s;
int f[55][55];

int main() {
  memset(f, 0x3f, sizeof(f));
  cin >> s;

  int n = s.size();

  for (int i = 0; i < n; ++i) {
    f[i][i] = 1;
  }

  for (int l = 2; l < n + 1; ++l) {
    for (int i = 0; i < n - l + 1; ++i) {
      int j = i + l - 1;
      if (s[i] == s[j]) {
        f[i][j] = f[i][j - 1];
      } else {
        for (int k = i; k < j; ++k) {
          f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
      }
    }
  }

  cout << f[0][n - 1] << endl;
}