#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/description/

class Solution
{
public:
    int findChanges(vector<int> &nums, int diff, int k)
    {
        int ans = 0;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            int a = nums[i];
            int b = nums[nums.size() - 1 - i];
            if (abs(a - b) != diff)
            {
                bool oneChangePossible = false;
                if (a + diff <= k || a - diff >= 0)
                {
                    oneChangePossible = true;
                }
                if (b + diff <= k || b - diff >= 0)
                {
                    oneChangePossible = true;
                }
                if (oneChangePossible)
                {
                    ans += 1;
                }
                else
                {
                    ans += 2;
                }
            }
        }
        return ans;
    }
    int minChanges(vector<int> &nums, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = nums.size();
        unordered_map<int, int> differences;
        for (int i = 0; i < n; i++)
        {
            differences[abs(nums[i] - nums[n - i - 1])]++;
        }
        vector<pair<int, int>> diffFreq;
        int ans = INT_MAX;
        for (auto &diff : differences)
        {
            diffFreq.push_back({diff.second, diff.first});
        }
        sort(diffFreq.rbegin(), diffFreq.rend());
        for (int i = 0; i < diffFreq.size(); i++)
        {
            int tempAns = findChanges(nums, diffFreq[i].second, k);
            if (ans < tempAns)
            {
                break;
            }
            ans = tempAns;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};