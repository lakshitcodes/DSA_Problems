#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int chairNumber=1;
        int startTarget = times[targetFriend][0];
        int endTarget = times[targetFriend][1];
        cout<<startTarget<<" "<<endTarget;
        sort(times.begin(),times.end());
        int n=times.size();
        vector<int> chair(n+1,0);
        for(int i=0;i<times.size();i++){
            for(int j=0;j<=n;j++){
                if(times[i][0]>=chair[j]){
                    chair[j]=times[i][1];
                    if(times[i][0]==startTarget && times[i][1]==endTarget){
                        return j;
                    }
                    break;
                }
            }
        }
        return n-1;
    }
};