#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-covered-buildings/

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int, set<int>> rowMap;
        unordered_map<int, set<int>> colMap;

        for (const auto &b : buildings)
        {
            int x = b[0], y = b[1];
            rowMap[y].insert(x);
            colMap[x].insert(y);
        }

        int covered = 0;

        for (const auto &b : buildings)
        {
            int x = b[0], y = b[1];

            auto &row = rowMap[y];
            bool hasLeft = *row.begin() < x;
            bool hasRight = *row.rbegin() > x;

            auto &col = colMap[x];
            bool hasUp = *col.begin() < y;
            bool hasDown = *col.rbegin() > y;

            if (hasLeft && hasRight && hasUp && hasDown)
            {
                covered++;
            }
        }

        return covered;
    }
};