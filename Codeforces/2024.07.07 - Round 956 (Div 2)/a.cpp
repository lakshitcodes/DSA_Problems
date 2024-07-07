#include <bits/stdc++.h>
using namespace std;

// Question Link : https://codeforces.com/contest/1983/problem/A

/*
A. Array Divisibility
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
An array of integers a1,a2,⋯,an is beautiful subject to an integer k if it satisfies the following:

The sum of aj over all j such that j is a multiple of k and 1≤j≤n, itself, is a multiple of k.
More formally, if ∑k|jaj is divisible by k for all 1≤j≤n then the array a is beautiful subject to k. Here, the notation k|j means k divides j, that is, j is a multiple of k
.
Given n, find an array of positive nonzero integers, with each element less than or equal to 105 that is beautiful subject to all 1≤k≤n.
It can be shown that an answer always exists.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows.

The first and only line of each test case contains a single integer n (1≤n≤100) — the size of the array.

Output
For each test case, print the required array as described in the problem statement.
*/

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
        for (int i = 1; i <= n; i++)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}