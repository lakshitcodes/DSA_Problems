#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/regular-expression-matching/

class Solution {
    public:
        vector<vector<int>> dp;
        
        bool solve(int i, int j, string& s, string& p) {
            if (j == p.length()) return i == s.length(); // If pattern is exhausted, check if string is also exhausted
            if (dp[i][j] != -1) return dp[i][j]; // Memoization
    
            bool first_match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));
    
            if (j + 1 < p.length() && p[j + 1] == '*') {
                // Case 1: Ignore '*' and preceding character (match zero times)
                // Case 2: Use '*' to match more characters (only if first_match is true)
                return dp[i][j] = (solve(i, j + 2, s, p) || (first_match && solve(i + 1, j, s, p)));
            } else {
                return dp[i][j] = (first_match && solve(i + 1, j + 1, s, p));
            }
        }
    
        bool isMatch(string s, string p) {
            dp = vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, -1));
            return solve(0, 0, s, p);
        }
    };
    