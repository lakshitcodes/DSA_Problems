#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(items.begin(),items.end());
        unordered_map<int,int> mp;
        mp[items[0][0]]=items[0][1];
        vector<int> prices;
        prices.push_back(items[0][0]);
        for(int i=1;i<items.size();i++){
            mp[items[i][0]]=max({mp[items[i][0]],items[i][1],mp[items[i-1][0]]});
            if(items[i][0]!=prices.back()){
                prices.push_back(items[i][0]);
            }
        }
        vector<int> ans;
        for(auto &i : queries){
            if(mp.find(i)!=mp.end()){
                ans.push_back(mp[i]);
            }
            else if(i<prices[0]){
                ans.push_back(0);
            }
            else{
                auto it = lower_bound(prices.begin(),prices.end(),i);
                if(it!=prices.begin())
                    --it;
                ans.push_back(mp[*it]);
                
            }
        }
        return ans;
    }
};