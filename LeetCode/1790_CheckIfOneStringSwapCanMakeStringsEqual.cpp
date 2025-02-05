#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count=0;
        vector<int> a1(26,0),a2(26,0);
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
            }
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;
        }
        return (count==0 || count==2) && a1==a2;
    }
};