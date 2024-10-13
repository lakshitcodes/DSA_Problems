#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-maximum-removals-from-source-string/

class Solution {
public:
    vector<int> vis;
    vector<vector<int>> dp;
    int f(string& source, string& pattern, int i, int j) {
        if(j == pattern.length()) return 0;
        if(i == source.length()) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int perform = f(source, pattern, i+1, j);
        int notPerform = INT_MAX;
        if(source[i] == pattern[j]) {
            int x = 0;
            if(vis[i]) x = 1;

            int y = f(source, pattern, i+1, j+1);
            if(y != INT_MAX)
                notPerform = x + y;
        }
        return dp[i][j] = min(notPerform, perform);
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        vis.resize(n, 0);
        dp.resize(n, vector<int>(pattern.length(), -1));

        for(auto it: targetIndices) vis[it] = 1;
        int ans = f(source, pattern, 0, 0);

        if(ans == INT_MAX) ans = 0;
        return targetIndices.size() - ans;
    }
};