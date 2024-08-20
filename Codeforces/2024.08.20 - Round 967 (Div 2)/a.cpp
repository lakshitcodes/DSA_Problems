#include <bits/stdc++.h>
using namespace std;

/*
A. Make All Equal
time limit per test1 second
memory limit per test256 megabytes
You are given a cyclic array a1,a2,…,an.

You can perform the following operation on a at most n−1 times:

Let m be the current size of a, you can choose any two adjacent elements where the previous one is no greater than the latter one (In particular, am and a1 are adjacent and am is the previous one), and delete exactly one of them. In other words, choose an integer i (1≤i≤m) where ai≤a(imodm)+1 holds, and delete exactly one of ai or a(imodm)+1 from a.

Your goal is to find the minimum number of operations needed to make all elements in a equal.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤500). The description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤100) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — the elements of array a.

Output
For each test case, output a single line containing an integer: the minimum number of operations needed to make all elements in a equal.
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
        vi arr(n);
        take(arr);

        int maxFreq = 0;
        unordered_map<int, int> freq;
        for (auto &i : arr)
        {
            freq[i]++;
        }
        for (auto &i : freq)
        {
            maxFreq = max(maxFreq, i.second);
        }

        cout << n - maxFreq << endl;
    }
    return 0;
}