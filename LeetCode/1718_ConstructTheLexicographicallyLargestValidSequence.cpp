#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/ 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> res;
    
    bool backtrack(vector<int>& ans, int index, vector<bool>& used, int n) {
        if (index == ans.size()) return true;
        
        if (ans[index] != 0) return backtrack(ans, index + 1, used, n);
        
        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;

            int j = (num == 1) ? index : index + num;
            if (j < ans.size() && ans[j] == 0) {
                ans[index] = ans[j] = num;
                used[num] = true;

                if (backtrack(ans, index + 1, used, n)) return true;

                ans[index] = ans[j] = 0;
                used[num] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans(2*n-1, 0);
        vector<bool> used(n + 1, false);
        
        backtrack(ans, 0, used, n);
        return ans;
    }
};
