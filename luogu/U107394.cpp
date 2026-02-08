#include <bits/stdc++.h>
using namespace std;

int n, m;
struct edge {
    int to, nxt;
};
int g[100010];
edge edges[100010];
int indegrees[100010];
int cnt = 1;

int main() {
    cin >> n >> m;
    for (int i = 1; i < m + 1; ++i) {
        int u, v;
        cin >> u >> v;
        edge e;
        e.to = v;
        e.nxt = g[u];
        g[u] = cnt;
        edges[cnt++] = e;
        ++indegrees[v];
    }

    priority_queue<int, vector<int>, greater<int>> h;
    vector<int> ans;
    ans.reserve(n);
    for (int i = 1; i < n + 1; ++i) {
        if (indegrees[i] == 0) {
            h.push(i);
        }
    }

    cnt = 0;
    while (!h.empty()) {
        int u = h.top();
        h.pop();
        ans.push_back(u);

        for (int i = g[u]; i != 0; i = edges[i].nxt) {
            if (--indegrees[edges[i].to] == 0) {
                h.push(edges[i].to);
            }
        }

        ++cnt;
    }


    if (cnt != n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}