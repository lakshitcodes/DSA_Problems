#include <bits/stdc++.h>
using namespace std;

/*

A. X Axis
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given three points with integer coordinates x1, x2, and x3 on the X axis (1≤xi≤10). You can choose any point with an integer coordinate a on the X axis. Note that the point a may coincide with x1, x2, or x3
. Let f(a) be the total distance from the given points to the point a. Find the smallest value of f(a).

The distance between points a and b is equal to |a−b|. For example, the distance between points a=5 and b=2 is 3.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤103) — the number of test cases. Then follows their descriptions.

The single line of each test case contains three integers x1, x2, and x3 (1≤xi≤10) — the coordinates of the points.

Output
For each test case, output the smallest value of f(a)
.*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> temp(3);
        for (auto &i : temp)
        {
            cin >> i;
        }
        sort(temp.begin(), temp.end());
        int ans = INT_MAX;
        for (int i = temp[0]; i <= temp[2]; i++)
        {
            ans = min(ans, abs(i - temp[0]) + abs(i - temp[1]) + abs(i - temp[2]));
        }
        cout << ans << endl;
    }
    return 0;
}