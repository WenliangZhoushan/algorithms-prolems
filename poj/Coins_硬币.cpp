#include <bits/stdc++.h>
using namespace std;

int n, m;
int values[110], nums[110];
bool f[2][100010];

void solve() {
    memset(f, 0, sizeof(f));
    f[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        int curr = i % 2;
        int next = (i + 1) % 2;
        for (int j = 0; j <= m; ++j) {
            f[next][j] = f[curr][j];
        }
        for (int k = 1; k <= nums[i]; ++k) {
            int weight = k * values[i];
            for (int j = weight; j <= m; ++j) {
                if (f[curr][j - weight]) {
                    f[next][j] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; ++j) {
        if (f[n % 2][j]) ans++;
    }

    cout << ans << endl;
}

int main() {
    while (cin >> n >> m && (n != 0 || m != 0)) {
        for (int i = 0; i < n; ++i) cin >> values[i];
        for (int i = 0; i < n; ++i) cin >> nums[i];
        solve();
    }
}