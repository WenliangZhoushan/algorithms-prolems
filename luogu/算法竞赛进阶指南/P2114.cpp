#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<pair<string, int>> doors;
    doors.reserve(N);

    for (int i = 0; i < N; ++i) {
        string op; int t;
        cin >> op >> t;
        doors.emplace_back(op, t);
    }

    int x0 = 0, x1 = ~0;

    auto f = [&](int x) -> int {
        for (auto& [op, t] : doors) {
            if (op == "AND") {
                x &= t;
            } else if (op == "OR") {
                x |= t;
            } else {
                x ^= t;
            }
        }
        return x;
    };

    int a0 = f(x0), a1 = f(x1);
    int cnt = 0;

    for (int i = 30; i >= 0; --i) {
        int j = 1 << i;
        if (!(a0 & j) && !(a1 & j) || (cnt | j) > M) {
            continue;
        }
        if (a0 & j) {
            continue;
        } else if (a1 & j) {
            cnt |= j;
        }
    }

    cout << f(cnt) << endl;
}