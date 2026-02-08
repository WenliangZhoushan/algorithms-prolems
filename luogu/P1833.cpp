#include <bits/stdc++.h>
using namespace std;

int h1, h2, m1, m2;
char sep;
int n;
int costs[70010], values[70010], nums[70010];
int f[7010];

int main() {
    cin >> h2 >> sep >> m2 >> h1 >> sep >> m1 >> n;
    int t = h1 * 60 + m1 - h2 * 60 - m2;

    int j = 0;
    int T, C, P;
    for (int i = 0; i < n; ++i) {
        cin >> T >> C >> P;
        if (P == 0) {
            costs[j] = T; values[j] = C; nums[j] = P;
            ++j;
            continue;
        }
        for (int k = 1; k <= P; k <<= 1) {
            costs[j] = T * k; values[j] = C * k; nums[j] = k;
            P -= k;
            ++j;
        }
        if (P > 0) {
            costs[j] = T * P; values[j] = C * P; nums[j] = P;
            ++j;
        }
    }

    for (int i = 0; i < j; ++i) {
        if (nums[i] == 0) {
            for (int k = 0; k < t + 1; ++k) {
                if (costs[i] > k) {
                    continue;
                }
                f[k] = max(f[k], f[k - costs[i]] + values[i]);
            }
        } else {
            for (int k = t; k > 0; --k) {
                if (costs[i] > k) {
                    break;
                }
                f[k] = max(f[k], f[k - costs[i]] + values[i]);
            }
        }
    }

    cout << f[t] << endl;
}

/* 可ac，dp暴力枚举
#include <bits/stdc++.h>
using namespace std;

int h1, h2, m1, m2;
char sep;
int n;
int costs[10010], values[10010], nums[10010];
int f[1010];

int main() {
    cin >> h1 >> sep >> m1 >> h2 >> sep >> m2 >> n;
    int T, C, P;
    for (int i = 0; i < n; ++i) {
        cin >> T >> C >> P;
        costs[i] = T; 
        values[i] = C;
        nums[i] = P;
    }

    int t = h2 * 60 + m2 - h1 * 60 - m1;

    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            for (int j = 0; j < t + 1; ++j) {
                if (costs[i] > j) {
                    continue;
                }
                f[j] = max(f[j], f[j - costs[i]] + values[i]);
            }
        } else {
            for (int j = t; j > 0; --j) {
                for (int k = 1; k < nums[i] + 1; ++k) {
                    if (k * costs[i] > j) {
                        break;
                    } else {
                        f[j] = max(f[j], f[j - costs[i] * k] + values[i] * k);
                    }
                }
            }
        }
    }

    cout << f[t] << endl;
}
*/
