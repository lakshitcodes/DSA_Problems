#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/

class Solution {
    public:
        int maxSum(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_set<int> used;
            int ans=*max_element(nums.begin(),nums.end());
            used.insert(ans);
            for(auto &i : nums){
                if(used.count(i) || i<0){
                    continue;
                }
                ans+=i;
                used.insert(i);
            }
            return ans;
        }
    };