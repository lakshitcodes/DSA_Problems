#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-special-substring-of-length-k.cpp/

class Solution {
    public:
        bool isPossible(string s,int ind,int k){
            if(k+ind-1>=s.length()) return false;
            unordered_set<int> st;
            for(int i=ind;i<=ind+k-1;i++){
                st.insert(s[i]);
            }
            bool flag=true;
            if(ind-1>=0 && s[ind-1]==s[ind]){
                flag=false;
            }
    
            if(ind+k<s.length() && s[ind+k]==s[ind]){
                flag=false;
            }
            return st.size()==1 && flag;
        }
        bool hasSpecialSubstring(string s, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            for(int i=0;i<s.length();i++){
                if(isPossible(s,i,k)){
                    return true;
                }
            }
            return false;
        }
    };