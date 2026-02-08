#include <bits/stdc++.h>
using namespace std;

int n, bs;
long long nums[50010];
long long lazy[50010], s[50010];

void solve(int opt, int l, int r, int c) {
    int si = (l - 1) / bs, ei = (r - 1) / bs;
    if (opt == 0) {
        if (si == ei) {
            for (int i = l; i < r + 1; ++i) {
                nums[i] += c;
                s[si] += c;
            }
        } else {
            for (int i = l; i < (1 + si) * bs + 1; ++i) {
                nums[i] += c;
                s[si] += c;
            }
            for (int i = ei * bs + 1; i < r + 1; ++i) {
                nums[i] += c;
                s[ei] += c;
            }
            for (int i = si + 1; i < ei; ++i) {
                s[i] += c * bs;
                lazy[i] += c;
            }
        }
    } else {
        long long cnt = 0;
        if (si == ei) {
            for (int i = l; i < r + 1; ++i) {
                cnt += (nums[i] + lazy[si]) % (c + 1);
            }
        } else {
            for (int i = l; i < (1 + si) * bs + 1; ++i) {
                cnt += (nums[i] + lazy[si]) % (c + 1);
            }
            for (int i = ei * bs + 1; i < r + 1; ++i) {
                cnt += (nums[i] + lazy[ei]) % (c + 1);
            }
            for (int i = si + 1; i < ei; ++i) {
                cnt += s[i] % (c + 1);
            }
        }
        cout << cnt % (c + 1) << endl;
    }
}

int main() {
    cin >> n;
    bs = (int)sqrt(n);
    for (int i = 1; i < n + 1; ++i) {
        cin >> nums[i];
        s[(i - 1) / bs] += nums[i];
    }

    while (n--) {
        int opt, l, r, c;
        cin >> opt >> l >> r >> c;
        solve(opt, l, r, c);
    }
}