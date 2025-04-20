#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/rabbits-in-forest

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int ans=0;
            unordered_map<int,int> freq;
            for(auto &i : answers){
                if(freq.count(i)){
                    if(freq[i]<=i){
                        freq[i]++;
                        continue;
                    }
                    else{
                        freq[i]=0;
                    }
                }
                freq[i]++;
                ans+=i+1;
            }
            return ans;
        }
    };