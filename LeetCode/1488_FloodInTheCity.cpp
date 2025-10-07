#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/flood-in-the-city/

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = rains.size();
        list<int> dry;
        vector<int> ans(n, 13454);
        int idx = 0;
        unordered_map<int, int> full;
        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
            {
                dry.push_back(i);
                continue;
            }
            ans[i] = -1;
            if (full.count(rains[i]))
            {
                vector<int> tmp;
                while (dry.size() > 0 && dry.front() < full[rains[i]])
                {
                    tmp.push_back(dry.front());
                    dry.pop_front();
                }

                if (dry.size() == 0)
                {
                    return {};
                }
                else
                {
                    ans[dry.front()] = rains[i];
                    dry.pop_front();
                    full[rains[i]] = i;
                    for (int j = tmp.size() - 1; j >= 0; j--)
                    {
                        dry.push_front(tmp[j]);
                    }
                }
            }
            else
            {
                full[rains[i]] = i;
            }
        }

        return ans;
    }
};