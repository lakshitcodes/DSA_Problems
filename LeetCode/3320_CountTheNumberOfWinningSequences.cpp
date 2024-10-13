#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-the-number-of-winning-sequences/description/

class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int n;
    int solve(string &s, int last, int ind, int sum) {
        if (ind == n) return (sum >= 1);
        if (sum + n < 0 || sum + n > 2 * n) return 0;
        if (dp[ind][sum + n][last] != -1) return dp[ind][sum + n][last];
        
        long long cnt = 0;
        if (last != 1) {
            cnt = (cnt + solve(s, 1, ind + 1, (s[ind] == 'E') ? sum + 1 : ((s[ind] == 'W') ? sum - 1 : sum))) % mod;
        }
        if (last != 2) {
            cnt = (cnt + solve(s, 2, ind + 1, (s[ind] == 'F') ? sum + 1 : ((s[ind] == 'E') ? sum - 1 : sum))) % mod;
        }
        if (last != 3) {
            cnt = (cnt + solve(s, 3, ind + 1, (s[ind] == 'W') ? sum + 1 : ((s[ind] == 'F') ? sum - 1 : sum))) % mod;
        }
        
        return dp[ind][sum + n][last] = cnt;
    }
    
    int countWinningSequences(string s) {
        n = s.size();
        dp.resize(n + 1, vector<vector<int>>(2 * n + 1, vector<int>(4, -1)));
        return solve(s, 0, 0, 0) % mod;
    }
};