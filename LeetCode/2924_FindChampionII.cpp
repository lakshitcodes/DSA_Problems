#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-champion-ii/

// My code
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> outDeg(n,0);
        vector<int> inDeg(n,0);
        unordered_map<int,vector<int>> adj;
        for(auto &i : edges){
            outDeg[i[0]]++;
            inDeg[i[1]]++;
            adj[i[1]].push_back(i[0]);
        }
        int zero=0;
        for(int i=0;i<n;i++){
            zero+=inDeg[i]==0;
        }
        if(zero!=1){
            return -1;
        }
        vector<int> champ(n,0);
        vector<bool> visited(n,false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outDeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front = q.front();
            q.pop();
            visited[front]=true;
            for(auto &i : adj[front]){
                outDeg[i]--;
                if(outDeg[i]==0 && visited[i]==false){
                    champ[i]=max(champ[i],1+champ[front]);
                    q.push(i);
                }
            }
        }
        int maxVal=*max_element(champ.begin(),champ.end());
        int ans=-1;
        for(int i=0;i<n;i++){
            if(champ[i]==maxVal){
                if(ans!=-1){
                    return -1;
                }
                ans=i;
            }
        }
        return ans;
    }
};

// Most Optimized Code
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> inDeg(n,0);
        for(auto &i : edges){
            inDeg[i[1]]++;
        }
        int champ=-1;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                if(champ!=-1){
                    return -1;
                }
                champ=i;
            }
        }
        return champ;
    }
};