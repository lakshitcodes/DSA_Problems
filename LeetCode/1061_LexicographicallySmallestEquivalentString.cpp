#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

class Solution
{
public:
    class DSU
    {
    public:
        vector<int> parent;
        DSU()
        {
            parent.resize(26);
            for (int i = 0; i < 26; i++)
            {
                parent[i] = i;
            }
        }
        void unite(int a, int b)
        {
            int parA = findParent(a);
            int parB = findParent(b);

            if (parA != parB)
            {
                parent[max(parA, parB)] = min(parA, parB);
            }
        }
        int findParent(int x)
        {
            if (x == parent[x])
            {
                return x;
            }
            return parent[x] = findParent(parent[x]);
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        DSU ds;
        for (int i = 0; i < s1.length(); i++)
        {
            ds.unite(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for (auto &i : baseStr)
        {
            ans += 'a' + ds.findParent(i - 'a');
        }
        return ans;
    }
};