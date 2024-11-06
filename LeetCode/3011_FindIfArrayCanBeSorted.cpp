#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-if-array-can-be-sorted

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int currSetBits = __builtin_popcount(nums[0]);

        pair<int,int> prev = {INT_MAX,INT_MIN};
        pair<int,int> curr={nums[0],nums[0]};

        for(int i=1;i<nums.size();i++){
            int bitCount = __builtin_popcount(nums[i]);
            if(bitCount == currSetBits){
                curr.first = min(curr.first,nums[i]);
                curr.second = max(curr.second,nums[i]);
            }
            else{
                if(prev.second>curr.first){
                    cout<<i<<endl;
                    return false;
                }
                currSetBits = bitCount;
                prev=curr;
                curr={nums[i],nums[i]};
            }
        }
        return prev.second<=curr.first;
    }
};