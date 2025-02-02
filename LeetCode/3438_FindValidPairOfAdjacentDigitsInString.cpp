#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/

class Solution {
public:
    string findValidPair(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<char, int> freq;
    
        for (int i=0;i<s.length();i++) {
            freq[s[i]]++;
        }
        
        for (size_t i = 0; i < s.size() - 1; ++i) {
            if (s[i] != s[i + 1] && freq[s[i]] == s[i] - '0' && freq[s[i + 1]] == s[i + 1] - '0') {
                return string(1, s[i]) + string(1, s[i + 1]);
            }
        }
        
        return "";
    }
};