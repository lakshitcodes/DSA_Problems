#include <bits/stdc++.h>
using namespace std;

//Question Link : https://www.interviewbit.com/problems/subarray-with-given-xor/

class Solution{
    public:
    int solve(vector<int> &A, int B) {
        unordered_map<int,int> mp;
        int xr=0;
        mp[xr]++;
        long long count=0;
        for(int i=0;i<A.size();i++){
            xr^=A[i];
            int x=xr^B;
            count+=mp[x];
            mp[xr]++;
        }
        return count;
    }
  
};