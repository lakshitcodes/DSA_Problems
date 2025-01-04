#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

class Solution {
public:
    int findUnique(int start,int end,string s){
        unordered_set<char> st;
        for(int i=start+1;i<end;i++){
            st.insert(s[i]);
        }
        return st.size();
    }
    int countPalindromicSubsequence(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> lastIdx(26,-1),firstIdx(26,-1);
        for(int i=s.length()-1;i>=0;i--){
            if(lastIdx[s[i]-'a']==-1){
                lastIdx[s[i]-'a']=i;
            }
            firstIdx[s[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(firstIdx[i]!=-1 && lastIdx[i]!=-1){
                ans+=findUnique(firstIdx[i],lastIdx[i],s);
            }
        }
        return ans;

    }
};