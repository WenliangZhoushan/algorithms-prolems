#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) {
                cout << 1 << " \n"[j == i];
            } else {
                cout << 0 << " ";
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}