#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/combinations/

class Solution {
public:
    void solve(vector<bool> &mark,vector<int> &temp,int k,int n,vector<vector<int>> &ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        int i=1;
        if(!temp.empty()){
            i=temp.back();
        }
        for(;i<=n;i++){
            if(!mark[i]){
                mark[i]=true;
                temp.push_back(i);
                solve(mark,temp,k,n,ans);
                temp.pop_back();
                mark[i]=false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> mark(n+1,false);
        solve(mark,temp,k,n,ans);
        return ans;
    }
};