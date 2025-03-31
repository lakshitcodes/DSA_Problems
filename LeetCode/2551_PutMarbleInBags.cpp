#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/put-marbles-in-bags/

class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<int> adj;
            for(int i=1;i<weights.size();i++){
                adj.push_back(weights[i-1]+weights[i]);
            }
            sort(adj.begin(),adj.end());
            long long maxi=0;
            long long mini=0;
            for(int i=0;i<k-1;i++){
                mini+=adj[i];
                maxi+=adj[adj.size()-1-i];
            }
            return maxi-mini;
        }
    };