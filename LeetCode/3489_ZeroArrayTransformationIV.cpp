#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/zero-array-transformation-iv/

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            
            int n = nums.size();
            int m = queries.size();
    
            int l=0,r=m;
            int ans=-1;
            while(l<=r){
                int k=l + (r-l)/2;
                if (isPossible(nums, queries, k)) {
                    ans=k;
                    r=k-1;
                }
                else{
                    l=k+1;
                }
            }
            
            return ans;
        }
        
    private:
        bool isPossible(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
            int n = nums.size();
            vector<int> possible(n, true);
            
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0) continue; 
                
                vector<int> allowed;
                for (int j = 0; j < k; ++j) {
                    int l = queries[j][0], r = queries[j][1], val = queries[j][2];
                    if (l <= i && i <= r) {
                        allowed.push_back(val);
                    }
                }
                
                if (!isSubset(allowed, nums[i])) {
                    return false;
                }
            }
            
            return true;
        }
        
        bool isSubset(vector<int>& values, int target) {
            int n = values.size();
            vector<bool> dp(target + 1, false);
            dp[0] = true;
            
            for (int val : values) {
                for (int j = target; j >= val; --j) {
                    if (dp[j - val]) {
                        dp[j] = true;
                    }
                }
            }
            
            return dp[target];
        }
    };