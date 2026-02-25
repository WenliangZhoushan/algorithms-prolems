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

const int MOD = 1'000'000'007;
const int MAXN = 2005;
int n, k;
int f[MAXN][MAXN];

void solve() {
    for (int j = 1; j <= n; ++j) {
        f[1][j] = 1;
    }
    // debug_arr(f[1] + 1, n);
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int m = j; m <= n; m += j) {
                f[i + 1][m] = (f[i + 1][m] + f[i][j]) % MOD;
            }
        }
        // debug_arr(f[i] + 1, n);
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        ans = (ans + f[k][j]) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    solve();
}