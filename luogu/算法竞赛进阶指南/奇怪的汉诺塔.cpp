#include <bits/stdc++.h>
using namespace std;


int main() {
    int f[13], d[13];
    memset(f, 0x3f, sizeof(f));
    d[1] = 1;
    f[0] = f[1] = 1;

    for (int i = 2; i < 13; ++i) {
        d[i] = d[i - 1] * 2 + 1;
    }

    for (int i = 2; i < 13; ++i) {
        for (int j = 1; j < i; ++j) {
            f[i] = min(f[i], 2 * f[i - j] + d[j]);
        }
    }

    for (int i = 1; i < 13; ++i) {
        cout << f[i] << endl;
    }
}