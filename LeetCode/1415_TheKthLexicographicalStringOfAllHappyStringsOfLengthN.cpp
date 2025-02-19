#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

class Solution {
    public:
        void solve(string curr,int n,vector<string> &store,int k){
            if(store.size()>=k) return;
            if(n==0){
                store.push_back(curr);
                return;
            }
            if(curr.empty()){
                solve(curr+'a',n-1,store,k);
                solve(curr+'b',n-1,store,k);
                solve(curr+'c',n-1,store,k);
            }
            else{
                if(curr.back()=='a'){
                    solve(curr+'b',n-1,store,k);
                    solve(curr+'c',n-1,store,k);
                }
                if(curr.back()=='b'){
                    solve(curr+'a',n-1,store,k);
                    solve(curr+'c',n-1,store,k);
                }
                if(curr.back()=='c'){
                    solve(curr+'a',n-1,store,k);
                    solve(curr+'b',n-1,store,k);
                }
            }
        }
        string getHappyString(int n, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<string> store;
            solve("",n,store,k);
            if(store.size()<k){
                return "";
            }
            return store[k-1];
        }
    };