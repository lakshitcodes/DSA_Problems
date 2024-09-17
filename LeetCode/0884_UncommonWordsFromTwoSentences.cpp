#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/uncommon-words-from-two-sentences/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<string,int> count;
        for(int i=0;i<s1.length();i++){
            string temp="";
            while(i<s1.length() && s1[i]!=' '){
                temp+=s1[i++];
            }
            count[temp]++;
        }
        for(int i=0;i<s2.length();i++){
            string temp="";
            while(i<s2.length() && s2[i]!=' '){
                temp+=s2[i++];
            }
            count[temp]++;
        }
        vector<string> ans;
        for(auto &i : count){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};