#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2){
                ans.push_back(-1);
                continue;
            }
            for(int j=0;j<=10000;j++){
                if((j|(j+1))==nums[i]){
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};