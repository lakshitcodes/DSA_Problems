#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-subarray-with-equal-products/

class Solution {
public:
    const int mod=1e9+7;
    int lcm(int a, int b) {
        return (a * b) / __gcd(a, b);
    }
    int maxLength(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        int maxLength = 1;
        
        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int gcdVal = nums[i];
            int lcmVal = nums[i];
            
            for (int j = i; j < n; ++j) {
                prod = (prod*nums[j])%mod;
                gcdVal = __gcd(gcdVal, nums[j]);
                lcmVal = lcm(lcmVal, nums[j]);
                
                if (prod == lcmVal * gcdVal) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
        return maxLength;
    }
};