#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/

class Solution
{
public:
    bool isPossible(vector<int> &tasks, vector<int> &workers, int pills, int strength, int k)
    {
        deque<int> changed;
        int j = workers.size() - 1;

        for (int t = k - 1; t >= 0; t--)
        {
            int task = tasks[t];
            if (!changed.empty() && changed.front() >= task)
            {
                changed.pop_front();
            }
            else if (j >= 0 && workers[j] >= task)
            {
                j--;
            }
            else
            {
                while (j >= 0 && workers[j] + strength >= task)
                {
                    changed.push_back(workers[j--]);
                }
                if (changed.empty() || pills == 0)
                {
                    return false;
                }
                changed.pop_back();
                --pills;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());

        int l = 0, r = min(tasks.size(), workers.size());
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (isPossible(tasks, workers, pills, strength, mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};