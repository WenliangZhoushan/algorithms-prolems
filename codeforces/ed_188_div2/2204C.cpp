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

ll t, a, b, c, m;

void solve() {
    cin >> a >> b >> c >> m;
    ll ab = lcm(a, b);
    ll ac = lcm(a, c);
    ll bc = lcm(b, c);
    ll abc = lcm(a, bc);
    ll A = m / a - m / ab - m / ac + m / abc;
    ll B = m / b - m / ab - m / bc + m / abc;
    ll C = m / c - m / bc - m / ac + m / abc;
    ll AB = m / ab - m / abc;
    ll AC = m / ac - m / abc;
    ll BC = m / bc - m / abc;
    ll ABC = m / abc;
    cout << 6 * A + 3 * AB + 3 * AC + 2 * ABC << ' ';
    cout << 6 * B + 3 * AB + 3 * BC + 2 * ABC << ' ';
    cout << 6 * C + 3 * AC + 3 * BC + 2 * ABC << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        solve();
    }
}
