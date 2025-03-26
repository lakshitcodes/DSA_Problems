#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

class Solution {
    public:
        int findMoves(vector<int> &store,int x,int index){
            int med=store[index];
            int ans=0;
            for(auto &i : store){
                ans+=abs(i-med)/x;
            }
            return ans;
        }
        int minOperations(vector<vector<int>>& grid, int x) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<int> store;
            for(auto &i : grid){
                for(auto &j : i){
                    store.push_back(j);
                }
            }
            sort(store.begin(),store.end());
            for(int i=1;i<store.size();i++){
                if((store[i]-store[i-1])%x!=0){
                    return -1;
                }
            }
            if(store.size()%2){
                return findMoves(store,x,store.size()/2);
            }
            return min(findMoves(store,x,store.size()/2),findMoves(store,x,store.size()/2 -1));
        }
    };