#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<int> notPossible(banned.begin(),banned.end());
        int count=0;
        for(int i=1;i<=n;i++){
            if(notPossible.count(i)){
                continue;
            }
            if(maxSum-i>=0){
                maxSum-=i;
                count++;
            }
            else{
                return count;
            }
        }
        return count;
    }
};