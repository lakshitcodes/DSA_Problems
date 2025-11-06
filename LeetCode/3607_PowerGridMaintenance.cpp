#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/power-grid-maintenance/

class Solution
{
public:
    class DSU
    {
    public:
        vector<int> rank, parent;
        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int findParent(int r)
        {
            if (parent[r] == r)
            {
                return r;
            }
            return parent[r] = findParent(parent[r]);
        }
        void unite(int u, int v)
        {
            int a = findParent(u);
            int b = findParent(v);
            if (a == b)
            {
                return;
            }
            if (rank[a] > rank[b])
            {
                parent[b] = a;
            }
            else if (rank[a] < rank[b])
            {
                parent[a] = b;
            }
            else
            {
                parent[b] = a;
                rank[a]++;
            }
        }
    };
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<bool> operational(c, true);
        DSU ds(c);
        for (auto &i : connections)
        {
            ds.unite(i[0] - 1, i[1] - 1);
        }
        vector<int> ans;
        unordered_map<int, set<int>> mp;
        for (int i = 0; i < c; i++)
        {
            mp[ds.findParent(i)].insert(i);
        }
        for (auto &i : queries)
        {
            if (i[0] == 2)
            {
                mp[ds.findParent(i[1] - 1)].erase(i[1] - 1);
                operational[i[1] - 1] = false;
            }
            else
            {
                if (operational[i[1] - 1])
                {
                    ans.push_back(i[1]);
                }
                else
                {
                    int parent = ds.findParent(i[1] - 1);
                    if (mp[parent].size() == 0)
                    {
                        ans.push_back(-1);
                    }
                    else
                    {
                        ans.push_back(*(mp[parent].begin()) + 1);
                    }
                }
            }
        }
        return ans;
    }
};