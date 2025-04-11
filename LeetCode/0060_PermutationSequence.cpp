#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/permutation-sequence/description/

class Solution {
    public:
        vector<int> factorial;
        void solve(int n,int k,string &ans,vector<bool> &visited){
            if(n==0){
                return;
            }
            if(k==1){
                for(int i=1;i<visited.size();i++){
                    if(!visited[i]){
                        visited[i]=true;
                        ans+=to_string(i);
                    }
                }
                return;
            }
            int req=(k-1)/factorial[n-1];
            int mult=req;
            int index=-1;
            for(int i=1;i<visited.size();i++){
                if(!visited[i]){
                    if(req==0){
                        index=i;
                        break;
                    }
                    req--;
                }
            }
            visited[index]=true;
            ans+=to_string(index);
    
            solve(n-1,k-mult*factorial[n-1],ans,visited);
    
        }
        string getPermutation(int n, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            factorial.resize(n+1);
            factorial[0]=1;
            for(int i=1;i<=n;i++){
                factorial[i]=factorial[i-1]*i;
            }
    
            vector<bool> visited(n+1,false);
            string ans="";
            solve(n,k,ans,visited);
            return ans;
        }
    };