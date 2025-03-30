#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-cost-to-reach-every-position/

class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
    
            vector<int> ans(cost.size(),0);
            ans[0]=cost[0];
            for(int i=1;i<cost.size();i++){
                ans[i]=min(ans[i-1],cost[i]);
            }
            return ans;
        }
    };