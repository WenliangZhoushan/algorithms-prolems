#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << "}"; }
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debug_arr(a, n) do { cerr << #a << " = ["; for (int i = 0; i < (n); ++i) { if (i) cerr << ", "; cerr << (a)[i]; } cerr << "]" << endl; } while(0)
#define line() cerr << "--------------------" << endl

const int INF = 0x3f3f3f3f;
const int NEG_INF = 0xcfcfcfcf;

int t, n, k, p, m;

void solve() {
    cin >> n >> k >> p >> m;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;
    ll cost1 = nums[p - 1], c = max(0, p - k);
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + p - 1);
    while (c--) {
        cost1 += pq.top();
        pq.pop();
    }
    if (cost1 > m) {
        cout << 0 << endl;
        return;
    }
    vector<int> nums2;
    for (int i = 0; i < n; ++i) {
        if (i == p - 1) continue;
        nums2.push_back(nums[i]);
    }
    sort(all(nums2));
    ll cost2 = reduce(nums2.begin(), nums2.begin() + n - k, 0LL) + nums[p - 1];
    cout << 1 + (m - cost1) / cost2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        solve();
    }
}
