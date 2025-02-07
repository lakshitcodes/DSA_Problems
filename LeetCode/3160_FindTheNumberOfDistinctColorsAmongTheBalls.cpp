#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int,int> colors;
        unordered_map<int,int> ballToColor;
        vector<int> ans;
        for(auto &i : queries){
            int ball=i[0];
            int color=i[1];

            if(ballToColor.find(ball)!=ballToColor.end()){
                colors[ballToColor[ball]]--;
                if(colors[ballToColor[ball]]==0){
                    colors.erase(ballToColor[ball]);
                }
            }
            ballToColor[ball]=color;
            colors[color]++;
            ans.push_back(colors.size());
        }
        return ans;
    }
};