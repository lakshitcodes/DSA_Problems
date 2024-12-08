#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(),nums.end());
        if(k>nums[0]){
            return -1;
        }
        unordered_set<int> st;
        for(int i:nums){
            if(i>k){
                st.insert(i);
            }
        }
        return st.size();
    }
};