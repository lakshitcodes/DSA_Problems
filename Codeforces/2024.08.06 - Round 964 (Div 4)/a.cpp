#include <bits/stdc++.h>
using namespace std;

/*
A. A+B Again?
time limit per test1 second
memory limit per test256 megabytes
Given a two-digit positive integer n, find the sum of its digits.

Input
The first line contains an integer t (1≤t≤90) — the number of test cases.

The only line of each test case contains a single two-digit positive integer n (10≤n≤99).

Output
For each test case, output a single integer — the sum of the digits of n.
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
        int ans = 0;
        while (n > 0)
        {
            ans += n % 10;
            n /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}