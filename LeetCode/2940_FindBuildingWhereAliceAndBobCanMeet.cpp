#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=heights.size();
        int qSize=queries.size();

        vector<int> ans(qSize,-1);
        vector<pair<int,int>> idx;

        for(int i=0;i<qSize;i++){
            int &x=queries[i][0], &y=queries[i][1];
            if(x>y){
                swap(x,y);
            }
            if(x==y || heights[x]<heights[y]){
                ans[i]=y;
            }
            else{
                idx.push_back({y,i});
            }
        }

        sort(idx.begin(),idx.end(),greater<>());
        vector<pair<int,int>> stack;

        int j=n-1;
        for(auto [_,i] : idx){
            int x=queries[i][0];
            int y=queries[i][1];

            for(;j>y;j--){
                while(!stack.empty() && heights[stack.back().second]<heights[j]){
                    stack.pop_back();
                }
                stack.emplace_back(heights[j],j);
            }

            auto it=upper_bound(stack.rbegin(),stack.rend(),make_pair(heights[x],n));
            ans[i]=(it==stack.rend()) ? -1 : it->second;
        }
        return ans;
    }
};