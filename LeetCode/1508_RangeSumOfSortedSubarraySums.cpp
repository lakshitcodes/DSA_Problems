#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> subarray;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                subarray.push_back(sum);
            }
        }
        sort(subarray.begin(),subarray.end());

        int ans=0;
        const int mod = 1e9+7;
        for(int i=left-1;i<right;i++){
            ans+=subarray[i];
            ans%=mod;
        }
        return ans;
    }
};