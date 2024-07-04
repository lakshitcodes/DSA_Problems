#include <bits/stdc++.h>
using namespace std;

/*
B. Maximum Multiple Sum
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given an integer n, find an integer x such that:2≤x≤n.
The sum of multiples of x that are less than or equal to n is maximized. Formally, x+2x+3x+⋯+kx where kx≤n is maximized over all possible values of x.
InputThe first line contains t (1≤t≤100) — the number of test cases.

Each test case contains a single integer n (2≤n≤100).

Output
For each test case, output an integer, the optimal value of x
. It can be shown there is only one unique answer.
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 3)
        {
            cout << n << endl;
            continue;
        }
        cout << 2 << endl;
    }
    return 0;
}