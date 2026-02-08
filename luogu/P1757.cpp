#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int f[110][1010];

int main() {
    cin >> m >> n;
    unordered_map<int, vector<pair<int, int>>> g;
    int mx = -1;

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[c].emplace_back(a, b);
        mx = max(mx, c);
    }

    for (int i = 0; i < mx + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            f[i + 1][j] = f[i][j];
        }
        if (!g.contains(i)) {continue;}
        for (int j = 0; j < m + 1; ++j) {
            for (auto& [c, v] : g[i]) {
                if (c > j) {
                    continue;
                }
                f[i + 1][j] = max({f[i + 1][j], f[i][j], f[i][j - c] + v});
            }
        }
    }

    cout << f[mx + 1][m] << endl;
}