#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/rotating-the-box/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m=box.size();
        int n=box[0].size();

        vector<vector<char>> ans(n,vector<char>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][i]=box[m-1-i][j];
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                int curr=i;
                while(curr>=0 && ans[curr][j]=='.'){
                    curr--;
                }
                if(curr>=0 && ans[curr][j]=='#'){
                    swap(ans[curr][j],ans[i][j]);
                }
            }
        }    
        return ans;
    }
};