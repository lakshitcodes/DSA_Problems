#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/shortest-palindrome/

class Solution {
public:
    string shortestPalindrome(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string x=s;
        reverse(x.begin(),x.end());
        string finder = s+ '#' + x;
        int count = KMP(finder);
        string add = s.substr(count);
        reverse(add.begin(),add.end());
        return add+s;
    }
    int KMP(string s){
        int n=s.length();
        vector<int> pi(n,0);
        int index=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[index]){
                pi[i]=pi[i-1]+1;
                index++;
            }
            else{
                index=pi[i-1];
                while(index>0 && s[index]!=s[i]){
                    index=pi[index-1];
                }
                if(s[i]==s[index]){
                    index++;
                }
                pi[i]=index;
            }
        }
        return pi.back();
    }
};