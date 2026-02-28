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

const int MAXN = 10005;
int t, n;
int edges[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> edges[i];
    }
    if (edges[1] == 1) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << endl;
        return;
    }
    if (edges[n] == 0) {
        for (int i = 1; i <= n; ++i) cout << i << " ";
        cout << n + 1 << " ";
        cout << endl;
        return;
    }
    int j = -1;
    for (int i = 1; i <= n - 1; ++i) {
        if (edges[i] == 0 && edges[i + 1] == 1) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
        if (i == j) {
            cout << n + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        solve();
    }
}
