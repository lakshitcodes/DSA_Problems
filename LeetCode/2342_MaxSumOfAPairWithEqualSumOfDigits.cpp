#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution {
    public:
        int sum(int n){
            int ans=0;
            while(n>0){
                ans+=n%10;
                n/=10;
            }
            return ans;
        }
        int maximumSum(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<int> storeMax(100,-1);
            int ans=-1;
            for(auto &i : nums){
                int digSum = sum(i);
                if(storeMax[digSum]!=-1){
                    ans=max(ans,i+storeMax[digSum]);
                }
                storeMax[digSum]=max(storeMax[digSum],i);
            }
            return ans;
        }
    };