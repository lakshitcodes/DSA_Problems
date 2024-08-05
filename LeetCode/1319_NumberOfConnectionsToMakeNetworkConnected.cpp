#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-operations-to-make-network-connected/

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
            if (parent[i] == i)
            {
                return i;
            }
            int rr = findParent(parent[i]);
            parent[i] = rr;
            return rr;
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
    int countNumberOfComponents(int n, vector<vector<int>> &edges)
    {
        DisjointSet ds(n);
        for (auto &i : edges)
        {
            ds.unite(i[0], i[1]);
        }
        unordered_set<int> uniqueParents;
        for (int i = 0; i < n; ++i)
        {
            uniqueParents.insert(ds.findParent(i));
        }

        return uniqueParents.size();
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (connections.size() < n - 1)
        {
            return -1;
        }
        int components = countNumberOfComponents(n, connections);
        return components - 1;
    }
};