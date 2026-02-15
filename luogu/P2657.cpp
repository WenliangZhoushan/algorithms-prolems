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

int a, b;
string x;
int n;
int memo[10][11];

int dfs(int i, bool limit, bool isnum, int last) {
    if (i == n) {
        return isnum ? 1 : 0;
    }
    if (!limit && isnum && memo[i][last + 1] != -1) {
        return memo[i][last + 1];
    }
    int ans = 0;
    if (!isnum) {
        ans += dfs(i + 1, false, false, last);
    }
    int hi = limit ? x[i] - '0' : 9;
    int lo = isnum ? 0 : 1;
    for (int j = lo; j <= hi; ++j) {
        if (last != -1 && abs(last - j) < 2) {
            continue;
        }
        ans += dfs(i + 1, limit && j == x[i] - '0', true, j);
    }
    if (!limit && isnum) {
        memo[i][last + 1] = ans;
    }
    return ans;
}

int main() {
    cin >> a >> b;
    a--;
    memset(memo, -1, sizeof(memo));

    x = to_string(b);
    n = x.size();
    int ans1 = dfs(0, true, false, -1);
    memset(memo, -1, sizeof(memo));

    x = to_string(a);
    n = x.size();
    int ans2 = dfs(0, true, false, -1);

    cout << ans1 - ans2 << endl;
}