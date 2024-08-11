#include <bits/stdc++.h>
using namespace std;

/*
D1. DFS Checker (Easy Version)
time limit per test2 seconds
memory limit per test512 megabytes
This is the easy version of the problem. In this version, the given tree is a perfect binary tree and the constraints on n and q are lower. You can make hacks only if both versions of the problem are solved.

You are given a perfect binary tree† consisting of n vertices. The vertices are numbered from 1 to n, and the root is the vertex 1. You are also given a permutation p1,p2,…,pn of [1,2,…,n].

You need to answer q queries. For each query, you are given two integers x, y; you need to swap px and py and determine if p1,p2,…,pn is a valid DFS order‡ of the given tree.

Please note that the swaps are persistent through queries.

†
 A perfect binary tree is a tree with vertex 1 as its root, with size n=2k−1 for a positive integer k, and where the parent of each vertex i (1<i≤n) is ⌊i2⌋. Thus, all leaves of this tree are at a distance k−1 from the root.

‡
 A DFS order is found by calling the following dfs function on the given tree.

dfs_order = []

function dfs(v):
    append v to the back of dfs_order
    pick an arbitrary permutation s of children of v
    for child in s:
        dfs(child)
dfs(1)
Note that the DFS order is not unique.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains two integers n, q (3≤n≤65535, 2≤q≤5⋅104) — the number of vertices in the tree and the number of queries. It is guaranteed that n=2k−1 for a positive integer k.

The next line contains n−1 integers a2,a3,…,an (1≤ai<i) — the parent of each vertex in the given tree. It is guaranteed that ai=⌊i2⌋.

The next line contains n integers p1,p2,…,pn (1≤pi≤n, all pi are distinct) — the initial permutation p.
The next q lines each contain two integers x, y (1≤x,y≤n,x≠y) — the positions of the elements to swap in the permutation.

It is guaranteed that the sum of all n does not exceed 65535, and the sum of all q does not exceed 5⋅104.

Output
For each test case, print q lines corresponding to the q queries. For each query, output YES if there is a DFS order that exactly equals the current permutation, and output NO
 otherwise.

You can output Yes and No in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).
*/

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define take(arr)       \
    for (auto &i : arr) \
        cin >> i;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vi a(n, -1);
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        vi p(n);
        take(p);
        for (auto &i : p)
        {
            i--;
        }
        vi positions(n);
        for (int i = 0; i < n; i++)
        {
            positions[p[i]] = i;
        }
        ll good = 0;
        vector<set<int>> s(n);
        vi f(n);
        vvi adj(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (i > 0)
            {
                adj[a[i]].emplace_back(i);
            }
            for (auto &element : adj[i])
            {
                f[i] += f[element];
            }
            f[i]++;
        }
        int notGood = 0;

        // Func1
        auto calculate = [&](int index)
        {
            if (s[index].empty())
            {
                return false;
            }
            int x = positions[index];
            int y = *s[index].begin();
            return y < x;
        };
        // Func2
        auto deleteFromSet = [&](int i, int x)
        {
            auto iter = s[i].find(x);
            int l = -1, r = -1;
            if (iter != s[i].begin())
            {
                l = *prev(iter);
                if (l + f[p[l]] != x)
                {
                    notGood -= 1;
                }
            }
            if (next(iter) != s[i].end())
            {
                r = *next(iter);
                if (x + f[p[x]] != r)
                {
                    notGood -= 1;
                }
            }
            if (l != -1 && r != -1)
            {
                if (l + f[p[l]] != r)
                {
                    notGood += 1;
                }
            }
            s[i].erase(iter);
        };
        // Func3
        auto addToSet = [&](int i, int x)
        {
            s[i].emplace(x);
            auto iter = s[i].find(x);
            int l = -1, r = -1;
            if (iter != s[i].begin())
            {
                l = *prev(iter);
                if (l + f[p[l]] != x)
                    notGood++;
            }
            if (next(iter) != s[i].end())
            {
                r = *next(iter);
                if (x + f[p[x]] != r)
                    notGood++;
            }
            if (l != -1 && r != -1)
            {
                if (i + f[p[l]] != r)
                    notGood--;
            }
        }; // Submitted from jainlakshit
        for (int i = 0; i < n; i++)
        {
            if (a[p[i]] != -1)
                addToSet(a[p[i]], i);
        }

        for (int i = 0; i < n; i++)
        {
            notGood += calculate(i);
        }
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            x -= 1;
            y -= 1;
            set<int> change;
            change.emplace(p[x]);
            change.emplace(p[y]);
            change.emplace(a[p[x]]);
            change.emplace(a[p[y]]);
            for (int z : change)
            {
                if (z != -1)
                    notGood -= calculate(z);
            }
            if (a[p[x]] != -1)
                deleteFromSet(a[p[x]], x);
            if (a[p[y]] != -1)
                deleteFromSet(a[p[y]], y);
            swap(p[x], p[y]);
            swap(positions[p[x]], positions[p[y]]);
            if (a[p[x]] != -1)
                addToSet(a[p[x]], x);
            if (a[p[y]] != -1)
                addToSet(a[p[y]], y);
            for (int z : change)
            {
                if (z != -1)
                    notGood += calculate(z);
            }

            cout << (notGood == 0 ? "YES\n" : "NO\n");
        }
    }

    return 0;
}