#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-ii/

class Solution {
    public:
        int longestPalindrome(string s, string t) {
            int m = s.size(), n = t.size(), ans = 0;
            
            // Step 1: Compute longest palindromic substrings in `s`
            vector<vector<bool>> dpS(m, vector<bool>(m, false)); // dpS[i][j] = true if s[i:j] is a palindrome
            vector<int> leftS(m, 0); // leftS[i] stores longest palindromic substring starting at i
            
            for (int i = m - 1; i >= 0; i--) {
                for (int j = i; j < m; j++) {
                    if (s[i] == s[j] && (j - i < 2 || dpS[i+1][j-1])) {
                        dpS[i][j] = true;
                        leftS[i] = max(leftS[i], j - i + 1);
                        ans = max(ans, leftS[i]);
                    }
                }
            }
            
            // Step 2: Compute longest palindromic substrings in `t`
            vector<vector<bool>> dpT(n, vector<bool>(n, false)); // dpT[i][j] = true if t[i:j] is a palindrome
            vector<int> rightT(n, 0); // rightT[j] stores longest palindromic substring ending at j
            
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i; j < n; j++) {
                    if (t[i] == t[j] && (j - i < 2 || dpT[i+1][j-1])) {
                        dpT[i][j] = true;
                        rightT[j] = max(rightT[j], j - i + 1);
                        ans = max(ans, rightT[j]);
                    }
                }
            }
            
            // Step 3: Compute longest common substring between `s` and `reverse(t)`
            vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j] stores length of longest common substring ending at s[i] and t[j]
            
            for (int i = 0; i < m; i++) {
                for (int j = n - 1; j >= 0; j--) {
                    if (s[i] == t[j]) {
                        dp[i][j] = 1;
                        if (i > 0 && j < n - 1) dp[i][j] += dp[i-1][j+1]; // Extend the mirrored substring
                    }
                    
                    if (dp[i][j]) {
                        int extra = 0;
                        if (i + 1 < m) extra = max(extra, leftS[i+1]); // Extend with palindromic prefix of s
                        if (j - 1 >= 0) extra = max(extra, rightT[j-1]); // Extend with palindromic suffix of t
                        
                        ans = max(ans, 2 * dp[i][j] + extra); // Compute final max palindrome length
                    }
                }
            }
            
            return ans; // Return the maximum palindrome length found
        }
    };
    