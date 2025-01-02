#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-vowel-strings-in-ranges/

class Solution {
public:
    inline bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool isValid(string s){
        return isVowel(s[0]) && isVowel(s.back());
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=words.size();
        vector<int> count(n,0);
        if(isValid(words[0])){
            count[0]=1;
        }
        for(int i=1;i<n;i++){
            count[i]=count[i-1];
            count[i]+=isValid(words[i]);
        }
        vector<int> ans;
        for(auto &i : queries){
            int temp = count[i[1]];
            if(i[0]>0){
                temp-=count[i[0]-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};