#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int tIndex=0;
        int tLength=str2.length();
        for(auto &c:str1){
            if(tIndex<tLength && (str2[tIndex]-c+26)%26<=1){
                tIndex++;
            }
        }
        return tIndex==tLength;
    }
};