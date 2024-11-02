#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/circular-sentence/

class Solution {
public:
    bool isCircularSentence(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=s.length();
        if(s[0]!=s[n-1]){
            return false;
        }

        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(s[i-1]!=s[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};