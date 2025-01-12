#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/check-if-a-parantheses-string-can-be-valid/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        if(s.length()%2)    return false;
        
        int count=0;
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0' || s[i]=='(') count++;
            else    count--;
            if(count<0) return false;
        }

        count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(locked[i]=='0' || s[i]==')') count++;
            else    count--;
            if(count<0) return false;
        }

        return true;
    }
};