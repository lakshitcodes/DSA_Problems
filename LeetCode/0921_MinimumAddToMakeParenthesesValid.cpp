#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        stack<char> st;
        for(auto c : s){
            if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        return st.size();
    }
};