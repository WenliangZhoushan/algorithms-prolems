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

int m;
string s;

vector<int> build_next(string& s) {
    int m = s.size();
    if (m == 1) {
        return {-1};
    }
    vector<int> nxt(m, -1);
    nxt[1] = 0;
    int i = 2, cn = 0;
    while (i < m) {
        if (s[i - 1] == s[cn]) {
            nxt[i++] = ++cn;
        } else if (cn == 0) {
            nxt[i++] = 0;
        } else {
            cn = nxt[cn];
        }
    }
    return nxt;
}

int kmp(string& s1, string& s2) {
    int n = s1.size(), m = s2.size(), x = 0, y = 0;
    vector<int> nxt = build_next(s2);
    while (x < n && y < m) {
        if (s1[x] == s2[y]) {
            ++x;
            ++y;
        } else if (y == 0) {
            ++x;
        } else {
            y = nxt[y];
        }
    }
    return y == m ? x - y : -1;
}

void solve() {
    cin >> m;
    cin >> s;

    vector<int> nxt(m + 1, -1);
    nxt[1] = 0;
    int i = 2, cn = 0;
    while (i <= m) {
        if (s[i - 1] == s[cn]) {
            nxt[i++] = ++cn;
        } else if (cn == 0) {
            nxt[i++] = 0;
        } else {
            cn = nxt[cn];
        }
    }

    cout << m - nxt.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
