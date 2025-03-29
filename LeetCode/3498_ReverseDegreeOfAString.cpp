#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/reverse-degree-of-a-string/

class Solution {
    public:
        int reverseDegree(string s) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ans=0;
            for(int i=0;i<s.length();i++){
                ans+=(i+1)*(26-(s[i]-'a'));
            }
            return ans;
        }
    };