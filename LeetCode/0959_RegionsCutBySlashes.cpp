#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/regions-cut-by-slashes/description/

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
    int regionsBySlashes(vector<string> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = grid.size();
        vector<vector<int>> graph(3 * n, vector<int>(3 * n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '/')
                {
                    int x = 3 * i;
                    int y = 3 * j;
                    graph[x + 2][y] = 1;
                    graph[x + 1][y + 1] = 1;
                    graph[x][y + 2] = 1;
                }
                if (grid[i][j] == '\\')
                {
                    int x = 3 * i;
                    int y = 3 * j;
                    graph[x][y] = 1;
                    graph[x + 1][y + 1] = 1;
                    graph[x + 2][y + 2] = 1;
                }
            }
        }
        DisjointSet ds(3 * n * 3 * n);
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int row = 0; row < 3 * n; row++)
        {
            for (int col = 0; col < 3 * n; col++)
            {
                if (graph[row][col] == 0)
                {
                    for (auto &[i, j] : directions)
                    {
                        int x = row + i;
                        int y = col + j;
                        if (x >= 0 && x < 3 * n && y >= 0 && y < 3 * n && graph[x][y] == 0)
                        {
                            ds.unionBySize(3 * n * row + col, 3 * n * x + y);
                        }
                    }
                }
            }
        }
        unordered_set<int> parents;
        for (int i = 0; i < 3 * n; i++)
        {
            for (int j = 0; j < 3 * n; j++)
            {
                if (graph[i][j] == 0)
                {
                    parents.insert(ds.findParent(i * 3 * n + j));
                }
            }
        }
        return parents.size();
    }
};