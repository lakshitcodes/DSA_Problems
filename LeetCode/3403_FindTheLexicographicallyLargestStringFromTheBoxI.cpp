#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/

class Solution {
public:
    string answerString(string word, int numFriends) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if(numFriends==1){
            return word;
        }
        int n = word.length();
        int maxLen = n - (numFriends - 1);
        string ans = "";
        
        char maxChar = word[0];
        for(char c : word) {
            maxChar = max(maxChar, c);
        }
        
        for(int i = 0; i < n; i++) {
            
            if(!ans.empty() && word[i] < ans[0]) continue;
            
            if(!ans.empty() && ans[0] == maxChar && word[i] != maxChar) continue;
            
            int limit = min(maxLen, n - i);
            string curr(1, word[i]);
            
            if(curr > ans) ans = curr;
            
            for(int j = 1; j < limit; j++) {
                curr += word[i + j];
                if(curr > ans) {
                    ans = curr;
                }
            }
        }
        
        return ans;
    }
};