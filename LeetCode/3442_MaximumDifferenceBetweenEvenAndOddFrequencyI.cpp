#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/

class Solution {
public:
    int maxDifference(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> freq(26,0);
        for(auto &i : s){
            freq[i-'a']++;
        }
        int odd=INT_MIN,even=INT_MIN;
        int modd=INT_MAX,meven=INT_MAX;
        for(auto &i : freq){
            if(i!=0){
            if(i%2==0){
                even=max(i,even);
                meven=min(i,meven);
            }
            else{
                odd=max(i,odd);
                modd=min(i,modd);
            }
            }
        }
        return max(odd-meven,modd-even);
    }
};