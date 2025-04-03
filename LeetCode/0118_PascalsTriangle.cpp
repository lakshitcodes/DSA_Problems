#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/pascals-triangle/

class Solution {
    public:
        vector<vector<int>> generate(int n) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            
            vector<vector<int>> ans;
            ans.push_back({1});
            if(n==1){
                return ans;
            }
            ans.push_back({1,1});
            if(n==2){
                return ans;
            }
            for(int i=2;i<n;i++){
                vector<int> temp;
                temp.push_back(1);
                for(int t=1;t<i;t++){
                    temp.push_back(ans[i-1][t]+ans[i-1][t-1]);
                }
                temp.push_back(1);
                ans.push_back(temp);
            }
            return ans;
        }
    };