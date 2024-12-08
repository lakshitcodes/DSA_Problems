#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=events.size();
        vector<tuple<int,bool,int>> time(2*n);
        for(int i=0;i<n;i++){
            int s=events[i][0];
            int e=events[i][1];
            int v=events[i][2];

            time[2*i]={s,0,v};
            time[2*i+1]={e,1,v};
        }
        sort(time.begin(),time.end());
        int ans=0,maxV=0,n2=2*n;

        for(auto& [t,isEnd,v]:time){
            if(isEnd) maxV=max(maxV,v);
            else ans=max(ans,maxV+v);
        }
        return ans;
    }
};