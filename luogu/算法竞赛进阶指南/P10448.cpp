#include <bits/stdc++.h>
using namespace std;

int n, m;

void dfs(vector<int>& nums, vector<int>& ans, int i) {
    if (ans.size() == m) {
        for (int j = 0; j < m; ++j) {
            printf("%d%c", ans[j], (j == m - 1 ? '\n' : ' '));
        }
        return;
    }

    for (int j = i; j < nums.size(); ++j) {
        ans.push_back(nums[j]);
        dfs(nums, ans, j + 1);
        ans.pop_back();
    }
}

void dfs2(vector<int>& nums, vector<int>& ans, int i) {
    if (ans.size() == m) {
        for (int j = 0; j < m; ++j) {
            printf("%d%c", ans[j], j == m - 1 ? '\n' : ' ');
        }
        return;
    }
    if (i == n) return;
    ans.push_back(nums[i]);
    dfs2(nums, ans, i + 1);
    ans.pop_back();
    dfs2(nums, ans, i + 1);
}

int main () {
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 1; i < n + 1; ++i) nums[i - 1] = i;

    vector<int> ans;
    ans.reserve(m);
    dfs(nums, ans, 0);
}