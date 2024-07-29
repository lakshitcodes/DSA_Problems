#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-number-of-teams/description/

class Solution
{
private:
    pair<int, int> findCount(vector<int> &rating, int start, int end, int element)
    {
        if (start > end)
        {
            return {0, 0};
        }
        int small = 0, large = 0;
        for (; start <= end; start++)
        {
            if (element < rating[start])
            {
                large++;
            }
            else if (element > rating[start])
            {
                small++;
            }
        }
        return {small, large};
    }

public:
    int numTeams(vector<int> &rating)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int n = rating.size();
        for (int i = 1; i < n - 1; i++)
        {
            pair<int, int> left = findCount(rating, 0, i - 1, rating[i]);
            pair<int, int> right = findCount(rating, i + 1, n - 1, rating[i]);
            // small,big
            // cout<<left.first<<" "<<left.second<<" "<<rating[i]<<" "<<right.first<<" "<<right.second<<endl;
            ans += left.first * right.second + left.second * right.first;
        }
        return ans;
    }
};