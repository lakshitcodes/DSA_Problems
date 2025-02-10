#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/clear-digits/

class Solution {
public:
    string clearDigits(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        stack<char> st;
        for(auto &i : s){
            if(i>='a' && i<='z'){
                st.push(i);
            }else{
                st.pop();
            }
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};