#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/

class Solution {
public:
    struct comparator{
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            return a.first==b.first ? a.second>b.second : a.first>b.first;
        }
    };
    long long findScore(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=nums.size();
        unordered_set<int> marked;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long score=0;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            if(marked.count(front.second)){
                continue;
            }
            score+=front.first;
            marked.insert(front.second);
            if(front.second-1>=0){
                marked.insert(front.second-1);
            }
            if(front.second+1<n){
                marked.insert(front.second+1);
            }
        }
        return score;
    }
};