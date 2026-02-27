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

int t;
int d;

bool primes[100000];

void solve() {
    cin >> d;

    vector<int> ans(3, 1);
    int i = 1, j = 2;
    while (i < 3) {
        while (!primes[j] || j - ans[i - 1] < d) ++j;
        ans[i++] = j;
    }
    cout << ans[1] * ans[2] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fill(primes, primes + 100000, true);
    primes[0] = false; primes[1] = false;
    for (int i = 2; i * i <= 100000; ++i) {
        if (primes[i]) {
            for (int j = i; i * j <= 100000; ++j) {
                primes[i * j] = false;
            }
        }
    }

    cin >> t;
    while (t--) {
        solve();
    }
}
