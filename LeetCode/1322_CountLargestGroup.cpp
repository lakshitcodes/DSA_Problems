#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-largest-group/

class Solution {
    public:
        int countLargestGroup(int n) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_map<int,int> mp;
            int maxiSize=0;
            int ans=0;
            for(int i=1;i<=n;i++){
                int val=i;
                int sum=0;
                while(val>0){
                    sum+=val%10;
                    val/=10;
                }
                mp[sum]++;
                if(mp[sum]>maxiSize){
                    ans=1;
                    maxiSize=mp[sum];
                }
                else if(maxiSize==mp[sum]){
                    ans++;
                }
            }
            return ans;
        }
    };