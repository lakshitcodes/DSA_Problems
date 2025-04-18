#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-and-say/

class Solution {
    public:
        string rle(string s){
            string ans="";
            char currChar=s[0];
            int currCount=1;
            for(int i=1;i<s.length();i++){
                if(s[i]==currChar){
                    currCount++;
                }
                else{
                    ans+='0'+currCount;
                    ans+=currChar;
                    currChar=s[i];
                    currCount=1;
                }
            }
            ans+=currCount+'0';
            ans+=currChar;
            return ans;
        }
        string countAndSay(int n) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            if(n==1){
                return string(1,'1');
            }
            return rle(countAndSay(n-1));
        }
    };