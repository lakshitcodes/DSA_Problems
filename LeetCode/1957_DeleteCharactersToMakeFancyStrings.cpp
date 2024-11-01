#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/delete-characters-to-make-fancy-string/

class Solution {
public:
    string makeFancyString(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if(s.length()<3){
            return s;
        }
        int j=2;
        for(int i=2;i<s.length();i++){
            if(s[i]!=s[j-1] || s[i]!=s[j-2]){
                s[j++]=s[i];
            }
        }
        s.resize(j);
        return s;
    }
};