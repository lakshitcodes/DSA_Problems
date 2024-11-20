#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

class Solution {
public:
    int takeCharacters(string s, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int a=0,b=0,c=0;
        for(char i : s){
            a+=i=='a';
            b+=i=='b';
            c+=i=='c';
        }
        if(a<k || b<k || c<k){
            return -1;
        }
        int res = INT_MAX;
        int l=0;
        for(int r=0;r<s.length();r++){
            a-=s[r]=='a';
            b-=s[r]=='b';
            c-=s[r]=='c';

            while(a<k || b<k || c<k){
                a+=s[l]=='a';
                b+=s[l]=='b';
                c+=s[l]=='c';
                l++;
            }
            res = min(res,(int)s.length()-(r-l+1));
        }
        return res;
    }
};