#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(int i, string& ans) {
    if (i == n) {
        cout << ans << endl;
        return;
    }
    ans += 'N';
    dfs(i + 1, ans);
    ans.pop_back();
    ans += 'Y';
    dfs(i + 1, ans);
    ans.pop_back();
}

int main() {
    cin >> n;
    string ans = "";

    dfs(0, ans);
}