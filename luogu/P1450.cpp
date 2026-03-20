#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << "}"; }
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debug_arr(a, n) do { cerr << #a << " = ["; for (int i = 0; i < (n); ++i) { if (i) cerr << ", "; cerr << (a)[i]; } cerr << "]" << endl; } while(0)
#define line() cerr << "--------------------" << endl

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

const int MAXM = 100000;
int t, s;
int coins[4];
int nums[4];
ll f[5][MAXM + 1];

void solve() {
    for (int i = 0; i < 4; ++i) cin >> nums[i];
    cin >> s;

    ll ans = 0;
    for (int mask = 1; mask < (1 << 4); ++mask) {
        int rem = s, cnt = 0;
        for (int i = 0; i < 4; ++i) {
            if ((mask >> i) & 1) {
                rem -= (nums[i] + 1) * coins[i];
                ++cnt;
            }
        }
        if (rem < 0) {
            continue;
        } else {
            ans += (cnt % 2) ? f[4][rem] : -f[4][rem];
        }
    }

    cout << f[4][s] - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; ++i) cin >> coins[i];
    f[0][0] = 1;
    for (int i = 0; i < 4; ++i) {
        int c = coins[i];
        for (int j = 0; j <= MAXM; ++j) {
            if (j < c) {
                f[i + 1][j] = f[i][j];
            } else {
                f[i + 1][j] = f[i][j] + f[i + 1][j - c];
            }
        }
    }

    cin >> t;
    while (t--) {
        solve();
    }
}
