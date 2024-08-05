#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/making-a-large-island/description/

class Solution
{
public:
    class DisjointSet
    {
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n)
        {
            rank.resize(n, 0);
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int i)
        {
            if (parent[i] == i)
            {
                return i;
            }
            int rr = findParent(parent[i]);
            parent[i] = rr;
            return rr;
        }
        void unionByRank(int a, int b)
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
        void unionBySize(int a, int b)
        {
            int r1 = findParent(a);
            int r2 = findParent(b);
            if (r1 == r2)
            {
                return;
            }
            if (size[r1] > size[r2])
            {
                parent[r2] = r1;
                size[r1] += size[r2];
            }
            else
            {
                parent[r1] = r2;
                size[r2] += size[r1];
            }
        }
    };
    bool isValid(int i, int j, int n)
    {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = grid.size();
        DisjointSet ds(n * n);
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                {
                    continue;
                }
                for (auto &[i, j] : directions)
                {
                    int x = row + i;
                    int y = col + j;
                    if (isValid(x, y, n) && grid[x][y] == 1)
                    {
                        ds.unionBySize(row * n + col, x * n + y);
                    }
                }
            }
        }
        int ans = 1;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                {
                    unordered_set<int> parents;
                    for (auto &[i, j] : directions)
                    {
                        int x = i + row;
                        int y = j + col;
                        if (isValid(x, y, n) && grid[x][y] == 1)
                        {
                            parents.insert(ds.findParent(x * n + y));
                        }
                    }
                    int tempAns = 1;
                    for (auto &i : parents)
                    {
                        tempAns += ds.size[i];
                    }
                    ans = max(ans, tempAns);
                }
                else
                {
                    ans = max(ans, ds.size[ds.findParent(row * n + col)]);
                }
            }
        }
        return ans;
    }
};