#include <bits/stdc++.h>
using namespace std;
/*
C. Update Queries
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's consider the following simple problem. You are given a string s of length n, consisting of lowercase Latin letters, as well as an array of indices ind of length m
 (1≤indi≤n) and a string c of length m, consisting of lowercase Latin letters. Then, in order, you perform the update operations, namely, during the i-th operation, you set sindi=ci
. Note that you perform all m operations from the first to the last.

Of course, if you change the order of indices in the array ind and/or the order of letters in the string c, you can get different results. Find the lexicographically smallest string s
 that can be obtained after m update operations, if you can rearrange the indices in the array ind and the letters in the string c as you like.

A string a is lexicographically less than a string b if and only if one of the following conditions is met:
a is a prefix of b, but a≠b;
in the first position where a and b differ, the symbol in string a is earlier in the alphabet than the corresponding symbol in string b.
Input
Each test consists of several sets of input data. The first line contains a single integer t
 (1≤t≤104) — the number of sets of input data. Then follows their description.

The first line of each set of input data contains two integers n and m (1≤n,m≤105) — the length of the string s and the number of updates.

The second line of each set of input data contains a string s of length n, consisting of lowercase Latin letters.
The third line of each set of input data contains m integers ind1,ind2,…,indm (1≤indi≤n) — the array of indices ind.

The fourth line of each set of input data contains a string c of length m, consisting of lowercase Latin letters.

It is guaranteed that the sum of n over all sets of input data does not exceed 2⋅105. Similarly, the sum of m over all sets of input data does not exceed 2⋅105.

Output
For each set of input data, output the lexicographically smallest string s that can be obtained by rearranging the indices in the array ind and the letters in the string c as you like.*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, v;
        cin >> n >> v;
        string s;
        cin >> s;
        vector<int> index(v);
        for (auto &i : index)
        {
            cin >> i;
        }
        string m;
        cin >> m;
        sort(m.begin(), m.end());
        vector<bool> possible(n, false);
        for (auto &i : index)
        {
            possible[i - 1] = true;
        }
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (possible[i])
            {
                s[i] = m[idx];
                idx++;
            }
        }
        cout << s << endl;
    }
    return 0;
}