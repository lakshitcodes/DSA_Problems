#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/assign-elements-to-groups-with-constraints/

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = groups.size();
        vector<int> ans(n);
        
        vector<int> pre(100001, -1);
        for (int i = 0; i < elements.size(); i++) {
            if (pre[elements[i]] == -1) {
                pre[elements[i]] = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            int group = groups[i];
            int bestIndex = -1;
            int bestValue = INT_MAX;
            
            for (int j = 1; j * j <= group; j++) {
                if (group % j == 0) {
                    if (pre[j] != -1) {
                        int idx = pre[j];
                        if (idx < bestIndex || bestIndex == -1) {
                            bestIndex = idx;
                            bestValue = j;
                        }
                    }
                    
                    int quotient = group / j;
                    if (quotient != j && pre[quotient] != -1) {
                        int idx = pre[quotient];
                        if (idx < bestIndex || bestIndex == -1) {
                            bestIndex = idx;
                            bestValue = quotient;
                        }
                    }
                }
            }
            
            ans[i] = bestIndex;
        }
        
        return ans;
        
    }
};