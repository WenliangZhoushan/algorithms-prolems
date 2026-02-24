#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define fi first
#define se second

int N, M;
pii f[100005];
int cnt[100005];
priority_queue<pll, vector<pll>, less<pll>> mx;

int earn(int i) {
    auto& [k, b] = f[i];
    int x = cnt[i];
    return b + (x + 1) * k + x * k;
}

int main() {
    cin >> N >> M;
    int k, b;
    for (int i = 0; i < M; ++i) {
        cin >> k >> b;
        f[i] = make_pair(k, b);
        mx.push(make_pair(earn(i), i));
    }
    long long ans = 0;

    while (N && !mx.empty() && mx.top().fi > 0) {
        auto [x, i] = mx.top();
        mx.pop();
        ++cnt[i];
        ans += x;
        --N;
        mx.push(make_pair(earn(i), i));
    }

    cout << ans << endl;
}