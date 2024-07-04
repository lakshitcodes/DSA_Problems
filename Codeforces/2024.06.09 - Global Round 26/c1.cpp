#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
C1. Magnitude (Easy Version)
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The two versions of the problem are different. You may want to read both versions. You can make hacks only if both versions are solved.

You are given an array a of length n. Start with c=0. Then, for each i from 1 to n (in increasing order) do exactly one of the following:

Option 1: set c to c+ai.
Option 2: set c to |c+ai|, where |x| is the absolute value of x.
Let the maximum final value of c after the procedure described above be equal to k. Find k.

Input
The first line contains a single integer t
 (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105).

The second line of each case contains n integers a1, a2, a3, …, an (−109≤ai≤109).

The sum of n over all test cases does not exceed 3⋅105.

Output
For each test case, output a single integer — the value of k
.*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> nums(n);
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
            sum1 += nums[i];
            sum2 += nums[i];
            sum1 = abs(sum1);
        }
        sum2 = abs(sum2);
        if (sum1 > sum2)
        {
            cout << sum1 << endl;
        }
        else
        {
            cout << sum2 << endl;
        }
    }

    return 0;
}