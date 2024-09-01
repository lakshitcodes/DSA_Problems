#include <bits/stdc++.h>
using namespace std;

/*
C. Longest Good Array
time limit per test2 seconds
memory limit per test256 megabytes
Today, Sakurako was studying arrays. An array a of length n is considered good if and only if:

the array a is increasing, meaning ai−1<ai for all 2≤i≤n;
the differences between adjacent elements are increasing, meaning ai−ai−1<ai+1−ai for all 2≤i<n.
Sakurako has come up with boundaries l and r and wants to construct a good array of maximum length, where l≤ai≤r for all ai.

Help Sakurako find the maximum length of a good array for the given l and r.

Input
The first line contains a single integer t (1≤t≤104)  — the number of test cases.

The only line of each test case contains two integers l and r (1≤l≤r≤109).

Output
For each test case, output a single integer  — the length of the longest good array Sakurako can form given l and r
.
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
        ll l, r;
        cin >> l >> r;
        long long range_diff = r - l;
        long long max_length = 0;
        long long k = 0;
        while (k * (k + 1) / 2 <= range_diff)
        {
            max_length = k + 1;
            k++;
        }

        cout << max_length << endl;
    }
    return 0;
}