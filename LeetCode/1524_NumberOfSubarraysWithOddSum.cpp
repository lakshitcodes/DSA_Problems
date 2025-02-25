#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
    public:
        const int mod=1e9+7;
        int numOfSubarrays(vector<int>& arr) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            long long ans=0;
            bool isOdd=false;
            vector<int> store={1,0};
            for(auto &i : arr){
                isOdd^=(i&1);   // If already odd , then it will be even and vice versa
                ans+=store[1-isOdd];
                ans%=mod;
                store[isOdd]++;
            }
            return ans;
    
        }
    };