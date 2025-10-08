#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                                long long success)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = potions.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());

        for (int i : spells)
        {
            int pos = lower_bound(potions.begin(), potions.end(),
                                  ceil((double)success / i)) -
                      potions.begin();
            ans.push_back(n - pos);
        }
        return ans;
    }
};