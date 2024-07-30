#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://www.geeksforgeeks.org/problems/number-of-provinces/1

class Solution
{
public:
    class DisjointSet
    {
    public:
        vector<int> parent;
        vector<int> rank;

        DisjointSet(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i)
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

        void unionFind(int a, int b)
        {
            int parent1 = findParent(a);
            int parent2 = findParent(b);

            if (parent1 != parent2)
            {
                if (rank[parent1] > rank[parent2])
                {
                    parent[parent2] = parent1;
                }
                else if (rank[parent1] < rank[parent2])
                {
                    parent[parent1] = parent2;
                }
                else
                {
                    parent[parent2] = parent1;
                    ++rank[parent1];
                }
            }
        }
    };

    int numProvinces(vector<vector<int>> &isConnected, int n)
    {
        DisjointSet ds(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isConnected[i][j])
                {
                    ds.unionFind(i, j);
                }
            }
        }

        unordered_set<int> uniqueParents;
        for (int i = 0; i < n; ++i)
        {
            uniqueParents.insert(ds.findParent(i));
        }

        return uniqueParents.size();
    }
};
