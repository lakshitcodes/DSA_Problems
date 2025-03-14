#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution {
    public:
        bool isPossible(vector<int> &candies,long long k,int mid){
            for(auto &i : candies){
                k-=i/mid;
            }
            return k<=0;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int l=1;
            int r=*max_element(candies.begin(),candies.end());
            int ans=0;
            while(l<=r){
                int mid=l + (r-l)/2;
                if(isPossible(candies,k,mid)){
                    ans=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            return ans;
        }
    };