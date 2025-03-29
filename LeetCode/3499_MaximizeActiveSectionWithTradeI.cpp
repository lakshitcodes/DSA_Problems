#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximize-active-section-with-trade-i/

class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ones=0;
            vector<int> zeroes;
            int curr=0;
            for(auto &i : s){
                if(i=='0'){
                    curr++;
                }
                else{
                    ones++;
                    if(curr)
                        zeroes.push_back(curr);
                    curr=0;
                }
            }
            if(curr){
                zeroes.push_back(curr);
            }
            if(zeroes.size()<2){
                return ones;
            }
            int ans=0;
            for(int i=0;i<zeroes.size()-1;i++){
                ans=max(ans,zeroes[i]+zeroes[i+1]);
            }
            return ones+ans;
        }
    };