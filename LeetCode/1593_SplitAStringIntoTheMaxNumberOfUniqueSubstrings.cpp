#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

class Solution {
public:
    int solve(int index,string s,set<string>&ans){
        if(index==s.length()){
            return 0;
        }
        int maxVal=0;
        for(int i=index+1;i<=s.length();i++){
            string curr = s.substr(index,i-index);
            if(ans.find(curr)==ans.end()){
                ans.insert(curr);
                maxVal=max(maxVal,1+solve(i,s,ans));
                ans.erase(curr);
            }
        }
        return maxVal;
    }
    int maxUniqueSplit(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        set<string> ans;
        return solve(0,s,ans);
    }
};