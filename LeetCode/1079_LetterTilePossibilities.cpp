#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
    public:
        int count=0;
        void solve(string curr,int index,unordered_set<string> &st,vector<bool> &visited,string tiles){
            count++;
            if(index==tiles.size()){
                st.insert(curr);
                return;
            }
            for(int i=0;i<tiles.size();i++){
                if(!visited[i]){
                    visited[i]=true;
                    solve(curr,index+1,st,visited,tiles);
                    solve(curr+tiles[i],index+1,st,visited,tiles);
                    visited[i]=false;
                }
            }
        }
        int numTilePossibilities(string tiles) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_set<string> st;
            vector<bool> visited(tiles.size(),false);
            solve("",0,st,visited,tiles);
            // -1 because of empty string
            cout<<count;
            return st.size()-1;
        }
    };