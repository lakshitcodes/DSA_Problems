#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=questions.size();
            vector<long long> dp(n,0);
            dp[n-1]=questions[n-1][0];
            for(int i=n-2;i>=0;i--){
                dp[i]=dp[i+1];
                if(i+questions[i][1]+1<n){
                    dp[i]=max(dp[i],questions[i][0]+dp[i+questions[i][1]+1]);
                }else{
                    dp[i]=max(dp[i],(long long)questions[i][0]);
                }
            }
            return dp[0];
        }
    };