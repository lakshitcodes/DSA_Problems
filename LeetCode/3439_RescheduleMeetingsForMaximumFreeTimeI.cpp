#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/

class Solution {
public:
    int maxFreeTime(int eventTime,int k, vector<int>& startTime, vector<int>& endTime) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = startTime.size();
        vector<pair<int, int>> meetings;
        
        for (int i = 0; i < n; ++i) {
            meetings.emplace_back(startTime[i], endTime[i]);
        }
        
        sort(meetings.begin(), meetings.end());
        
        vector<int> gaps;
        if(meetings[0].first!=0){
            gaps.push_back(meetings[0].first);
        }
        for (int i = 1; i < n; ++i) {
            gaps.push_back(meetings[i].first - meetings[i - 1].second);
        }
        if(meetings[n-1].second!=eventTime){
            gaps.push_back(eventTime-meetings[n-1].second);
        }
        int maxGap = 0, currentSum = 0;
        deque<int> dq;
        
        for (int i = 0; i < gaps.size(); ++i) {
            currentSum += gaps[i];
            dq.push_back(gaps[i]);
            
            if (dq.size() > k+1) {
                currentSum -= dq.front();
                dq.pop_front();
            }
            
            maxGap = max(maxGap, currentSum);
        }
        
        maxGap = max({maxGap, meetings[0].first, eventTime - meetings[n - 1].second});
        return maxGap;
    }
};