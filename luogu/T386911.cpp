// https://www.luogu.com.cn/problem/T386911
// TODO: 没过，记得补一下

#include <bits/stdc++.h>
using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i < v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}
#define debug(x) cerr << #x << " = " << x << endl
#define debug_arr(a, n) do { cerr << #a << " = ["; for (int i = 0; i < (n); ++i) { if (i) cerr << ", "; cerr << (a)[i]; } cerr << "]" << endl; } while(0)
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debugline() cerr << "--------------------" << endl

const int MAXN = 100005;
int n;
int nums[MAXN];
int f[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int> cnt;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = cnt.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (cnt[m] <= nums[i]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (l == cnt.size()) {
            cnt.push_back(nums[i]);
        } else {
            cnt[l] = nums[i];
        }
        f[i] = l + 1;
    }

    // debug_arr(f, n);
    int t = *max_element(f, f + n);
    int i = n - 1, last = 0x3f3f3f3f;
    for (int j = n - 1; j >= 0; --j) {
        if (f[j] == t && nums[j] < last) {
            i = j;
            last = nums[i];
        }
    }
    vector<int> ans = {last};
    --t;
    while (t) {
        if (f[i] == t && nums[i] < last) {
            ans.push_back(nums[i]);
            --t;
        } else {
            --i;
        }
    }
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
} 