#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-the-hidden-sequences/description/

class Solution {
    public:
        #define ll long long
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            ll low=0,high=0;
            ll prev=0;
            for(int i: differences){
                ll curr=prev+i;
                low=min(curr,low);
                high=max(curr,high);
                prev=curr;
            }
            return max(upper-lower+1-high+low,0LL);
        }
    };