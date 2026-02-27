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
#define debugline() cerr << "--------------------" << endl

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

int t, n;

void solve() {
    cin >> n;
    int x = n;
    vector<pii> ans;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p != 0) {
            continue;
        }
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            ++cnt;
        }
        ans.emplace_back(p, cnt);
    }
    if (n > 1) ans.emplace_back(n, 1);
    if (sz(ans) >= 3) {
        cout << "YES" << endl;
        for (int i = 0; i < 3; ++i) {
            if (i < 2) {
                cout << ans[i].fi << " ";
            } else {
                cout << x / ans[0].fi / ans[1].fi << endl;
            }
        }
        return;
    }
    if (sz(ans) == 2) {
        if (ans[0].se + ans[1].se >= 4) {
            cout << "YES" << endl;
            cout << ans[0].fi << " " << ans[1].fi << " " << x / ans[0].fi / ans[1].fi << endl;
            return;
        }
    }
    if (sz(ans) == 1) {
        if (ans[0].se >= 6) {
            int a = ans[0].fi;
            cout << "YES" << endl;
            cout << a << " " <<  a * a << " " << x / a / a / a << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        solve();
    }
}
