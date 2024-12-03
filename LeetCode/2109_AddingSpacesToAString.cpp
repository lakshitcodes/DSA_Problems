#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/adding-spaces-to-a-string/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string temp="";
        int n=0;
        int space=spaces.size();
        int str=s.size();
        for(int i=0;i<str;i++){
            if(n<space && i==spaces[n]){
                n++;
                temp+=" ";
            }
            temp+=s[i];
            
        }
        return temp;
    }
};