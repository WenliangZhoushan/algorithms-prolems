#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int N, D;
    cin >> N >> D;
    vector<pair<int, int>> nums;
    nums.reserve(N);

    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        nums.emplace_back(x, y);
    }

    ranges::sort(nums, {}, &pair<int, int>::first);

    deque<int> mx, mn;
    int l = 0, ans = 0x3f3f3f3f;

    for (int r = 0; r < N; ++r) {
        while (!mx.empty() && nums[r].second >= nums[mx.back()].second) {
            mx.pop_back();
        }
        mx.push_back(r);
        while (!mn.empty() && nums[r].second <= nums[mn.back()].second) {
            mn.pop_back();
        }
        mn.push_back(r);
        while ((nums[mx.front()].second - nums[mn.front()].second) >= D) {
            ans = min(ans, nums[r].first - nums[l].first);
            if (mx.front() == l) {
                mx.pop_front();
            }
            if (mn.front() == l) {
                mn.pop_front();
            }
            ++l;
        }
    }

    cout << (ans < 0x3f3f3f3f ? ans : -1) << endl;
}