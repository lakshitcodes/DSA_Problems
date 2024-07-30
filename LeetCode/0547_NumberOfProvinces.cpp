#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-provinces/description/

// Using Disjoint set
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
        void unionFind(int a, int b)
        {
            int parent1 = findParent(a);
            int parent2 = findParent(b);
            if (parent1 == parent2)
            {
                return;
            }
            if (rank[parent1] > rank[parent2])
            {
                parent[parent1] = parent2;
            }
            else if (rank[parent2] > rank[parent1])
            {
                parent[parent2] = parent1;
            }
            else
            {
                rank[parent1]++;
                parent[parent2] = parent1;
            }
        }
    };
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        unordered_map<int, vector<int>> adjList;
        int n = isConnected.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for (auto &edge : adjList)
        {
            int u = edge.first;
            for (auto &i : edge.second)
            {
                ds.unionFind(u, i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            ds.findParent(i);
        }
        unordered_set<int> st;
        for (auto &i : ds.parent)
        {
            st.insert(i);
        }
        return st.size();
    }
};

//