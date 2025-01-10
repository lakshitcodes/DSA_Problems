#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/word-subsets/

class Solution {
public:
    int check(string& s1, unordered_map<char,int>& m){

        unordered_map<char,int> mp;
        for(auto x:s1){
            mp[x]++;
        }

        for(auto x:m){
            if(!mp.count(x.first) || mp[x.first]<x.second)
                return 0;
        }

        return 1;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        unordered_map<char,int> m;
        for(auto i:words2){

            vector<char> v(26,0);
            for(auto j:i){
                v[j-'a']++;
            }

            for(int k=0 ; k<26 ; k++){
                if(v[k]>0){ 
                    if(m[k+'a']<v[k])
                        m[k+'a']=v[k];
                }
            }
        }

        for(auto x:words1){
            if(check(x,m)){
                ans.push_back(x);
            }
        }

        return ans;
    }
};