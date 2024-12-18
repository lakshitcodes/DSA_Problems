#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        for(int i=0;i<prices.size();i++){
            bool valid=false;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=prices[i]){
                    ans.push_back(prices[i]-prices[j]);
                    valid=true;
                    break;
                }
            }
            if(!valid){
                ans.push_back(prices[i]);
            }
        }
        return ans;
    }
};