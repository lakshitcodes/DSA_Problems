#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if(s2.length()<s1.length()){
            return false;
        }
        vector<int> original(26,0);
        for(auto &c : s1){
            original[c-'a']++;
        }
        int n=s1.length();
        vector<int> second(26,0);
        for(int i=0;i<n;i++){
            second[s2[i]-'a']++;
        }
        if(original==second){
            return true;
        }
        for(int i=n;i<s2.length();i++){
            second[s2[i]-'a']++;
            second[s2[i-n]-'a']--;
            if(second==original){
                return true;
            }
        }
        return false;
    }
};