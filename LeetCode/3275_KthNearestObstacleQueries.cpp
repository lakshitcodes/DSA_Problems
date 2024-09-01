#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/k-th-nearest-obstacle-queries/

class Solution
{
public:
    vector<int> resultsArray(vector<vector<int>> &queries, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> results;
        priority_queue<int> maxHeap;

        for (auto &query : queries)
        {
            int distance = abs(query[0]) + abs(query[1]);
            maxHeap.push(distance);

            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }

            if (maxHeap.size() < k)
            {
                results.push_back(-1);
            }
            else
            {
                results.push_back(maxHeap.top());
            }
        }

        return results;
    }
};