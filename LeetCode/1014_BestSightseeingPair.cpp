#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/best-sightseeing-pair/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int maxNow = values[0]+0;
        int ans=maxNow;
        for(int i=1;i<values.size();i++){
            ans=max(ans,maxNow+values[i]-i);
            maxNow=max(maxNow,values[i]+i);
        }
        return ans;
    }
};