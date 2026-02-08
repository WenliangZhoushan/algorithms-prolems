#include <bits/stdc++.h>
using namespace std;

int N, H;
pair<int, int> cv[110];
int f[110][50010];

int main() {
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;

    cin >> N >> H;
    int P, C;
    for (int i = 0; i < N; ++i) {
        cin >> P >> C;
        cv[i] = make_pair(P, C);
    }

    for (int i = 0; i < N; ++i) {
        auto& [c, v] = cv[i];
        for (int j = 0; j < H + 1; ++j) {
            f[i + 1][j] = min(f[i][j], f[i + 1][max(0, j - c)] + v);
        }
    }

    cout << f[N][H] << endl;
}