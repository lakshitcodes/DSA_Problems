#include <bits/stdc++.h>
using namespace std;

/*
B. Minimize Equal Sum Subarrays
time limit per test1.5 seconds
memory limit per test256 megabytes
It is known that Farmer John likes Permutations, but I like them too!
— Sun Tzu, The Art of Constructing Permutations
You are given a permutation∗ p of length n.

Find a permutation q of length n that minimizes the number of pairs (i,j) (1≤i≤j≤n) such that pi+pi+1+…+pj=qi+qi+1+…+qj.

∗
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4 in the array).

Input
The first line contains t (1≤t≤104) — the number of test cases.

The first line of each test case contains n (1≤n≤2⋅105).

The following line contains n space-separated integers p1,p2,…,pn (1≤pi≤n) — denoting the permutation p of length n.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output one line containing any permutation of length n(the permutation q) such that q minimizes the number of pairs.
*/

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
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
        int n;
        cin >> n;
        vi p(n);
        take(p);
        vi q(n);
        for (int i = 0; i < n; ++i)
        {
            q[i] = p[(i + 1) % n];
        }
        for (auto &i : q)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}