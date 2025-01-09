#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/counting-words-with-given-prefix/

class Solution {
public:
    bool containsPrefix(string &word,string &pref){
        if(pref.length()>word.length()){
            return false;
        }
        for(int i=0;i<pref.length();i++){
            if(word[i]!=pref[i])    return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto i : words){
            ans+=containsPrefix(i,pref);
        }
        return ans;
    }
};