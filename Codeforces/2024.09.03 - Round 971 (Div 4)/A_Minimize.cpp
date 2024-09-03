#include <bits/stdc++.h>
using namespace std;

/*
A. Minimize!
time limit per test
1 second
memory limit per test
256 megabytes

You are given two integers aand b (a≤b). Over all possible integer values of c (a≤c≤b), find the minimum value of (c−a)+(b−c).
Input

The first line contains t(1≤t≤55) — the number of test cases.

Each test case contains two integers aand b (1≤a≤b≤10).
Output

For each test case, output the minimum possible value of (c−a)+(b−c) on a new line.
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
        int a, b;
        cin >> a >> b;
        cout << b - a << endl;
    }
    return 0;
}