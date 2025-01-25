#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<pair<int,int>> withIndex;
        int n=nums.size();
        for(int i=0;i<n;i++){
            withIndex.push_back({nums[i],i});
        }
        sort(withIndex.begin(),withIndex.end());

        vector<vector<pair<int,int>>> grouping = {{withIndex[0]}};

        for(int i=1;i<n;i++){
            if(withIndex[i].first-withIndex[i-1].first<=limit){
                grouping.back().push_back(withIndex[i]);
            }
            else{
                grouping.push_back({withIndex[i]});
            }
        }

        for(auto &group : grouping){
            vector<int> indexes;
            for(auto &i : group){
                indexes.push_back(i.second);
            }

            sort(indexes.begin(),indexes.end());
            for(int i=0;i<indexes.size();i++){
                nums[indexes[i]]=group[i].first;
            }
        }
        return nums;
    }
};