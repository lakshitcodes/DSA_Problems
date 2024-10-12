#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<intervals.size();i++){
            if(pq.top()<intervals[i][0]){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};