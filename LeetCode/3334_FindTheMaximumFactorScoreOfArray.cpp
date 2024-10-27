#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-maximum-factor-score-of-the-array/

class Solution {
public:
    long long findGcd(vector<int> &reduced){
        if(reduced.size()==0){
            return 0;
        }
        if(reduced.size()==1){
            return reduced[0];
        }
        long long gcd = __gcd(reduced[0],reduced[1]);
        for(int i=2;i<reduced.size();i++){
            gcd=__gcd(gcd,(long long)reduced[i]);
        }
        return gcd;
    }
    long long findLcm(vector<int> &reduced){
        if(reduced.size()==0){
            return 0;
        }
        if(reduced.size()==1){
            return reduced[0];
        }
        long long lcm = (reduced[0] * reduced[1]) / __gcd(reduced[0], reduced[1]);
        for(int i = 2; i < reduced.size(); i++){
            lcm = (reduced[i] * lcm) / __gcd(lcm, (long long)reduced[i]);
        }
        return lcm;
    }
    long long maxScore(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);


        long long ans=findGcd(nums)*findLcm(nums);
        for(int i=0;i<nums.size();i++){
            vector<int> temp;
            for(int j=0;j<nums.size();j++){
                if(j!=i){
                    temp.push_back(nums[j]);
                }
            }
            ans=max(ans,findLcm(temp)*findGcd(temp));
        }
        return ans;
    }
};