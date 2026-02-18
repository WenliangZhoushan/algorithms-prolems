#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int t, n;
string s;
bool cnt[MAXN];

void solve() {
    memset(cnt, false, sizeof(cnt));
    cin >> n;
    cin >> s;

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            if (s[j - 1] == '1') {
                break;
            } else if (cnt[j - 1]) {
                continue;
            } else {
                cnt[j - 1] = true;
                ans += i;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
}