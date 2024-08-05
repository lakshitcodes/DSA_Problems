#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/accounts-merge/

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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToIdx;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (emailToIdx.count(accounts[i][j]))
                {
                    ds.unite(emailToIdx[accounts[i][j]], i);
                }
                else
                {
                    emailToIdx[accounts[i][j]] = i;
                }
            }
        }
        vector<vector<string>> temp(n);
        for (auto &[mail, idx] : emailToIdx)
        {
            int parent = ds.findParent(idx);
            temp[parent].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (temp[i].size() == 0)
                continue;
            sort(temp[i].begin(), temp[i].end());
            vector<string> mails;
            mails.push_back(accounts[i][0]);
            for (auto &k : temp[i])
            {
                mails.push_back(k);
            }
            ans.push_back(mails);
        }
        return ans;
    }
};