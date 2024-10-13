#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/description/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2 || nums[i]==1){
                ans.push_back(-1);
                continue;
            }
            int num=log2(nums[i]);
            for(int j=num;j>=0;j--){
                int temp = nums[i]-pow(2,j);
                if((temp|(temp+1))==nums[i]){
                    ans.push_back(temp);
                    break;
                }
            }
        }
        return ans;
    }
};