// 单调队列优化组内枚举
#include <bits/stdc++.h>
using namespace std;

int n, W;
int values[110], costs[110], nums[110];
int f[2][40010];

int f1(int i, int j) {
    return j / costs[i] * values[i];
}

int main() {
    cin >> n >> W;
    int v, w, m;
    for (int i = 0; i < n; ++i) {
        cin >> v >> w >> m;
        values[i] = v; costs[i] = w; nums[i] = m;
    }
    deque<int> dq;

    for (int i = 0; i < n; ++i) {
        for (int mod = 0; mod < min(costs[i], W + 1); ++mod) {
            dq.clear();
            for (int j = mod; j < W + 1; j += costs[i]) {
                while (!dq.empty() && j - dq.front() > costs[i] * nums[i]) {
                    dq.pop_front();
                }
                while (!dq.empty() && f[i % 2][j] - f1(i, j) >= f[i % 2][dq.back()] - f1(i, dq.back())) {
                    dq.pop_back();
                }
                dq.push_back(j);
                f[(i + 1) % 2][j] = f1(i, j) + f[i % 2][dq.front()] - f1(i, dq.front());
            }
        }
    }

    cout << f[n % 2][W] << endl;
}

// 二进制优化枚举 + 暴力组内枚举
// #include <bits/stdc++.h>
// using namespace std;

// int n, W;
// /* 原版 
// int costs[110], values[110], nums[110];
// int f[110][40010];
// */
// int costs[2200], values[2200], nums[2200]; // log_2^m
// int f[40010];

// int main () {
//     cin >> n >> W;
//     int v, w, m;
//     int j = 0;
//     for (int i = 0; i < n; ++i) {
//         cin >> v >> w >> m;
//         for (int k = 1; k <= m; k = (k << 1)) {
//             costs[j] = k * w; values[j] = k * v; nums[j] = k;
//             m -= k;
//             ++j;
//         }
//         if (m > 0) {
//             costs[j] = m * w; values[j] = m * v; nums[j] = m;
//             ++j;
//         }
//     }

//     for (int i = 0; i < j; ++i) {
//         for (int k = W; k > 0; --k) {
//             if (costs[i] > k) {
//                 break;
//             }
//             f[k] = max(f[k], f[k - costs[i]] + values[i]);
//         }
//     }

//     cout << f[W] << endl;

//     /* 枚举所有可能性，f[i + 1][j]固定情况下枚举[1...nums[i]]个物品。可AC
//     cin >> n >> W;
//     int v, w, m;
//     for (int i = 0; i < n; ++i) {
//         cin >> v >> w >> m;
//         costs[i] = w; values[i] = v; nums[i] = m;
//     }

//     for (int i = 0; i < n; ++i) {
//         int cost = costs[i], value = values[i], num = nums[i];
//         for (int j = 0; j < W + 1; ++j) {
//             for (int k = 0; k < num + 1; ++k) {
//                 if (k * cost > j) {
//                     f[i + 1][j] = max(f[i + 1][j], f[i][j]);
//                     break;
//                 } else {
//                     f[i + 1][j] = max(f[i + 1][j], f[i][j - k * cost] + k * value);
//                 }
//             }
//         }
//     }

//     cout << f[n][W] << endl;
//     */
// }