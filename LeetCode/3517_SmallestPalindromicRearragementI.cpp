#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/smallest-palindromic-rearrangement-i/

class Solution {
    public:
        string smallestPalindrome(string s) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<int> count(26,0);
            bool single=false;
            char ch='^';
            if(s.length()%2==1){
                single=true;
            }
            for(auto &i : s){
                count[i-'a']++;
            }
            string ans="";
            for(int i=0;i<26;i++){
                if(count[i]%2){
                    ch='a'+i;
                    count[i]--;
                }
                ans+=string(count[i]/2,'a'+i);   
            }
            string orig=ans;
            reverse(ans.begin(),ans.end());
            if(single)
                orig+=ch;
            orig+=ans;
            return orig;
            
        }
    };