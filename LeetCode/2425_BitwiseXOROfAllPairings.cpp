#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/bitwise-xor-of-all-pairings/

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n1=nums1.size()%2;
        int n2=nums2.size()%2;

        vector<int> count(32,0);

        for(auto &num : nums1){
            for(int i=31;i>=0;i--){
                if(num&(1<<i)){
                    count[i]+=n2;
                }
            }
        }
        for(auto &num : nums2){
            for(int i=31;i>=0;i--){
                if(num&(1<<i)){
                    count[i]+=n1;
                }
            }
        }
        int ans=0;

        for(int i=31;i>=0;i--){
            if(count[i]%2){
                ans+=1<<i;
            }
        }
        return ans;
    }
};