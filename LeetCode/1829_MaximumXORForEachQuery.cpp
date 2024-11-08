#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int constVal = (1<<maximumBit) -1;
        int n=nums.size();
        vector<int> ans(n,0);
        int currXor = 0;
        for(int i=0;i<n;i++){
            currXor^=nums[i];
            ans[n-1-i]=(currXor^constVal);
        }
        return ans;
    }
};