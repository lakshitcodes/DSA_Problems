#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        const int n=arr.size();
        int cnt=0, diff=0;
        for(int i=0; i<n; i++){
            diff+=arr[i]-i;
            cnt+=(diff==0);
        }
        return cnt;
    }
};