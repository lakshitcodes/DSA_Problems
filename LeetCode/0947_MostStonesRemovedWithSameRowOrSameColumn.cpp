#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class Solution
{
public:
    class DisjointSet
    {
    public:
        vector<int> rank, parent;
        DisjointSet(int n)
        {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }
        int findParent(int i)
        {
            if (parent[i] != i)
            {
                parent[i] = findParent(parent[i]);
            }
            return parent[i];
        }
        void unite(int a, int b)
        {
            int r1 = findParent(a);
            int r2 = findParent(b);
            if (r1 == r2)
            {
                return;
            }
            if (rank[r1] > rank[r2])
            {
                parent[r2] = r1;
            }
            else if (rank[r2] < rank[r1])
            {
                parent[r1] = r2;
            }
            else
            {
                rank[r1]++;
                parent[r2] = r1;
            }
        }
    };
    int removeStones(vector<vector<int>> &stones)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        for (auto &i : stones)
        {
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }
        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones)
        {
            int row = it[0];
            int col = maxRow + it[1] + 1;
            ds.unite(row, col);
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }
        int count = 0;
        for (auto nodes : stoneNodes)
        {
            cout << nodes.first << endl;
            if (ds.findParent(nodes.first) == nodes.first)
            {
                count++;
            }
        }
        return n - count;
    }
};