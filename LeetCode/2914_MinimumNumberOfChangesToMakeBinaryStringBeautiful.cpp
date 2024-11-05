#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/

class Solution {
public:
    int minChanges(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int count = 0 ;
        for(int i=0;i<s.length();i+=2){
            count+= s[i]!=s[i+1];
        }
        return count;
    }
};