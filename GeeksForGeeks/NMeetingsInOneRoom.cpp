#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      int maxMeetings(vector<int>& start, vector<int>& end) {
          int n=start.size();
          if(n<=1){
              return n;
          }
          vector<pair<int,int>> meetings;
          for(int i=0;i<n;i++){
              meetings.emplace_back(end[i],start[i]);
          }
          sort(meetings.begin(),meetings.end());
          int prev=meetings[0].first;
          int ans=1;
          for(int i=1;i<n;i++){
              if(meetings[i].second>prev){
                  ans++;
                  prev=meetings[i].first;
              }
          }
          return ans;
      }
  };