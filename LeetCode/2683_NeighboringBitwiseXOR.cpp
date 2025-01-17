#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/neighboring-bitwise-xor/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans=0;
        for(auto &i : derived){
            ans^=i;
        }
        return ans==0;
    }
};