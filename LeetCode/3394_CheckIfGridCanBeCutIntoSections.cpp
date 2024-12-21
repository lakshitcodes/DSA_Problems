#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

class Solution {
public:
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
        merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < merged.back()[1]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        
        vector<vector<int>> vertical;
        vector<vector<int>> horizontal;
        for(auto it: rectangles){
            vertical.push_back({it[1],it[3]}); // vertical view
            horizontal.push_back({it[0],it[2]}); // horizontal view
        }
        vector<vector<int>> mergeH= mergeIntervals(horizontal);
        vector<vector<int>> mergev= mergeIntervals(vertical);
        return mergeH.size()>=3 || mergev.size()>=3; 
    }
};