#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=part.length();
        for(int i=0;i<s.length();i++){
            if(i+n-1<s.length() && s.substr(i,n)==part){
                s.erase(i,n);
                i=-1;
            }
        }
        return s;
    }
};