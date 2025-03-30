#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-i/

class Solution {
    public:
        bool isPalindrome(string s){
            int i=0,j=s.length()-1;
            while(i<=j){
                if(s[i]!=s[j]){
                    return false;
                }
                i++,j--;
            }
            return true;
        }
        int longestPalindrome(string s, string t) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ans=1;
            for(int i=0;i<s.length();i++){
                string sCurr="";
                for(int j=i;j<s.length();j++){
                    sCurr+=s[j];
                    if(isPalindrome(sCurr)){
                        ans=max(ans,j-i+1);
                    }
                    for(int k=0;k<t.length();k++){
                        string tCurr="";
                        for(int h=k;h<t.length();h++){
                            tCurr+=t[h];
                            if(isPalindrome(tCurr)){
                                ans=max(ans,h-k+1);
                            }
                            if(isPalindrome(sCurr+tCurr)){
                                ans=max(j-i+1+h-k+1,ans);
                            }
                        }
                    }
                }
            }
            return ans;
        }
    };