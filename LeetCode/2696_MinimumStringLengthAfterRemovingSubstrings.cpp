#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

class Solution {
public:
    int minLength(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        stack<char> st;
        for(auto c : s){
            if(c=='B'){
                if(!st.empty() && st.top()=='A'){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
            else if(c=='D'){
                if(!st.empty() && st.top()=='C'){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
            else{
                st.push(c);
            }
        }
        return st.size();
    }
};