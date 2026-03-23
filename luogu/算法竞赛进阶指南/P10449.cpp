#include <bits/stdc++.h>
using namespace std;

int n;
int g[5][5];
int g_copy[5][5];
int inf = 0x3f3f3f3f;
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, -1, 1, 0, 0};

void change(int i, int j) {
  for (int k = 0; k < 5; ++k) {
    int x = dx[k], y = dy[k];
    if (i + x < 0 || i + x == 5 || j + y < 0 || j + y == 5) {
      continue;
    }
    g_copy[i + x][y + j] ^= 1;
  }
}

int check(int i) {
  for (int j = 0; j < 5; ++j) {
    if (g_copy[i][j] == 0) {
      return 0;
    }
  }
  return 1;
}

int dfs(int i) {
  if (i == 5) {
    return check(4) ? 0 : inf;
  }
  int cnt = 0;
  for (int j = 0; j < 5; ++j) {
    if (!g_copy[i - 1][j]) {
      change(i, j);
      ++cnt;
    }
  }
  return cnt + dfs(i + 1);
}

int solve() {
  int ans = inf;

  // operation for first row
  for (int op = 0; op <= (1 << 5) - 1; ++op) {
    memcpy(g_copy, g, sizeof(g));
    int cnt = 0;

    for (int i = 0; i < 5; ++i) {
      if ((1 << i) & op) {
        change(0, i);
        ++cnt;
      }
    }
    ans = min(ans, cnt + dfs(1));
  }

  return ans <= 6 ? ans : -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  string c;

  while (n--) {
    for (int i = 0; i < 5; ++i) {
      cin >> c;
      for (int j = 0; j < 5; ++j) {
        g[i][j] = c[j] - '0';
      }
    }
    cout << solve() << endl;
  }
}