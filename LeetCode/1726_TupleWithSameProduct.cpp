#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/tuple-with-same-product/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans=0;
        unordered_map<long long,int> freq;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                freq[nums[i]*nums[j]]++;
            }
        }
        for(auto &i : freq){
            if(i.second>=2){
                // if the frequency is k , then total number of handshakes (2 at a time) possible are
                // k*(k-1)/2
                // and for one , the permutations possible are 8
                ans+=i.second*(i.second-1)*4;
            }
        }
        return ans;
    }
};