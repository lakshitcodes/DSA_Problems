#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/calculate-score-after-performing-instructions/

class Solution {
    public:
        long long calculateScore(vector<string>& instructions, vector<int>& values) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=values.size();
            vector<bool> visited(n,false);
            long long ans=0;
            int i=0;
            while(i>=0 && i<n){
                if(visited[i]==true){
                    return ans;
                }
                if(instructions[i]=="jump"){
                    visited[i]=true;
                    i+=values[i];
                }
                else{
                    visited[i]=true;
                    ans+=values[i];
                    i++;
                }
            }
            return ans;
        }
};