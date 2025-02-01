#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/special-array-i/description/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]%2==nums[i+1]%2){
                return false;
            }
        }
        return true;
    }
};