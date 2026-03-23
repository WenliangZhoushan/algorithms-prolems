#include <bits/stdc++.h>
using namespace std;

int T, M;
// int f[110][1010];
int f[1010]; // space compress
int costs[110], values[110];

int main() {
  cin >> T >> M;
  for (int i = 0; i < M; ++i) {
    int c, v;
    cin >> c >> v;
    costs[i] = c;
    values[i] = v;
  }

  for (int i = 0; i < M; ++i) {
    for (int j = T; j > 0; --j) {
      if (costs[i] > j) {
        continue;
      } else {
        f[j] = max(f[j], f[j - costs[i]] + values[i]);
      }
    }
  }

  cout << f[T] << endl;
}