#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-width-ramp/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        stack<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()] >nums[i]){
                st.push(i);
            }
        }
        int maxLength=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                maxLength = max(maxLength,i-st.top());
                st.pop();
            }
        }
        return maxLength;
    }
};