// https://www.luogu.com.cn/problem/P1759
// TODO: 没过，输出方案数部分需要后缀dp

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105, MAXM = 205;
int m, v, n;
int f[MAXN][MAXM][MAXM];
int c1[MAXN], c2[MAXN], t[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> v >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c1[i] >> c2[i] >> t[i];
    }

    for (int i = 0; i < n; ++i) {
        int a = c1[i], b = c2[i], c = t[i];
        for (int j = 0; j <= m; ++j) {
            if (j < a) {
                for (int k = 0; k <= v; ++k) f[i + 1][j][k] = f[i][j][k];
                continue;
            }
            for (int k = 0; k <= v; ++k) {
                if (k < b) {f[i + 1][j][k] = f[i][j][k]; continue;}
                f[i + 1][j][k] = max(f[i][j][k], f[i][j - a][k - b] + c);
            }
        }
    }

    int ans = f[n][m][v];
    vector<int> cnt;
    int i = n, j = m, k = v;
    while (i) {
        if (f[i - 1][j][k] == f[i][j][k]) {
            --i;
        } else {
            cnt.push_back(i--);
            j -= c1[i]; k -= c2[i];
        }
    }
    reverse(cnt.begin(), cnt.end());

    cout << f[n][m][v] << endl;
    for (int i = 0; i < cnt.size(); ++i) {
        cout << cnt[i] << " \n"[i == cnt.size() - 1];
    } 
}