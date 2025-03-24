#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-days-without-meetings/

class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            
            if(meetings.size()==0){
                return 0;
            }
            sort(meetings.begin(),meetings.end());
            vector<pair<int,int>> mergedMeetings;
            int start=meetings[0][0];
            int end=meetings[0][1];
            for(int i=1;i<meetings.size();i++){
                if(meetings[i][0]<end+1){
                    end=max(meetings[i][1],end);
                }
                else{
                    mergedMeetings.push_back({start,end});
                    start=meetings[i][0];
                    end=meetings[i][1];
                }
                    
            }
            mergedMeetings.push_back({start,end});
            int ans=0;
            if(mergedMeetings[0].first>1){
                ans+=mergedMeetings[0].first-1;
            }
            for(int i=1;i<mergedMeetings.size();i++){
                ans+=mergedMeetings[i].first-mergedMeetings[i-1].second-1;
                
            }
            if(mergedMeetings.back().second<days){
                ans+=days-mergedMeetings.back().second;
            }
            return ans;
        }
    };