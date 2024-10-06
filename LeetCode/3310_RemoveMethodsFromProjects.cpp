#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/remove-methods-from-project/description/

class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int, vector<int>> adj;
        for (auto& i : invocations) {
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> sus(n, false);
        queue<int> q;
        q.push(k);
        unordered_set<int> susp,isus;
        for(int i=0;i<n;i++){
            
                isus.insert(i);
            
        }
        while (!q.empty()) {
            int element = q.front();
            q.pop();
            if (!sus[element]) {
                sus[element] = true;
                isus.erase(element);
                susp.insert(element);
                for (auto& i : adj[element]) {
                    q.push(i);
                }
            }
        }
        bool flag=false;
        for(auto &i : invocations){
            if(susp.count(i[0]) && isus.count(i[1])){
                flag=true;
            }
            if(susp.count(i[1]) && isus.count(i[0])){
                flag=true;
            }
        
        }
        
        vector<int> ans;
        for(auto &i : isus){
            ans.push_back(i);
        }
        if(flag){
            for(auto &i : susp){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};