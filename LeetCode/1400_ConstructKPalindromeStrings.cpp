#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/construct-k-palindrome-strings/

class Solution {
public:
    bool canConstruct(string s, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if(s.length()<k){
            return false;
        }
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        int odd=0;
        for(auto &i : count){
            odd+= i%2;
        }
        return odd<=k;
    }
};