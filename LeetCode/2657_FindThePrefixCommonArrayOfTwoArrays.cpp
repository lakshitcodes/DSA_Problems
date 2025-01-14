#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_set<int> mp;
        int currCount=0;
        vector<int> ans(A.size());
        for(int i=0;i<A.size();i++){
            if(mp.count(A[i])){
                currCount++;
            }
            mp.insert(A[i]);
            if(mp.count(B[i])){
                currCount++;
            }
            mp.insert(B[i]);
            ans[i]=currCount;
        }
        return ans;
    }
};