#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-the-number-of-fair-pairs/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans=0;
        auto start = nums.begin();
        auto end = nums.end();
        sort(start,end);
        for(int i=0;i<nums.size();i++){
            int first = lower-nums[i];
            int last = upper-nums[i];
            auto val = upper_bound(start+i+1,end,last)-lower_bound(start+i+1,end,first);
            ans+=val;
        }
        return ans;
    }
};