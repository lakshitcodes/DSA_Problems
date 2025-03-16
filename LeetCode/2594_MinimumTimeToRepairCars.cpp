#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-time-to-repair-cars/

class Solution {
    public:
        bool isPossible(vector<int> &ranks,int cars,long long time){
            for(auto &i : ranks){
                cars-=(int)sqrt(time/i);
                if(cars<=0){
                    return true;
                }
            }
            return false;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            long long l=1;
            long long r=*max_element(ranks.begin(),ranks.end())*(long long)cars*(long long)cars;
            long long ans=r;
            while(l<=r){
                long long mid=l+(r-l)/2;
                if(isPossible(ranks,cars,mid)){
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            return ans;
        }
    };