#include <bits/stdc++.h>
using namespace std;

/*
D. Mathematical Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s of length n>1, consisting of digits from 0 to 9. You must insert exactly n−2 symbols + (addition) or × (multiplication) into this string to form a valid arithmetic expression.

In this problem, the symbols cannot be placed before the first or after the last character of the string s, and two symbols cannot be written consecutively. Also, note that the order of the digits in the string cannot be changed. Let's consider s=987009
:

From this string, the following arithmetic expressions can be obtained: 9×8+70×0+9=81, 98×7×0+0×9=0, 9+8+7+0+09=9+8+7+0+9=33. Note that the number 09 is considered valid and is simply transformed into 9.
From this string, the following arithmetic expressions cannot be obtained: +9×8×70+09 (symbols should only be placed between digits), 98×70+0+9 (since there are 6 digits, there must be exactly 4 symbols).
The result of the arithmetic expression is calculated according to the rules of mathematics — first all multiplication operations are performed, then addition. You need to find the minimum result that can be obtained by inserting exactly n−2
 addition or multiplication symbols into the given string s.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Then follows their description.

The first line of each test case contains a single integer n (2≤n≤20) — the length of the string s.

The second line of each test case contains a string s of length n, consisting of digits from 0 to 9.

Output
For each test case, output the minimum result of the arithmetic expression that can be obtained by inserting exactly n−2 addition or multiplication symbols into the given string.
*/

vector<vector<long long>> dp(25, vector<long long>(25, -1));

long long dfs(string s, int pos, int count)
{
    if (count == 0)
        return stol(s.substr(pos));
    if (dp[pos][count] != -1)
        return dp[pos][count];
    long long result = 1e18;
    for (int i = pos; i < s.size() - count; i++)
    {
        long long a = stol(s.substr(pos, i - pos + 1));
        long long b = dfs(s, i + 1, count - 1);
        long long addition = a + b;
        long long multiplication = a * b;
        result = min({result, addition, multiplication});
    }
    return dp[pos][count] = result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << dfs(s, 0, n - 2) << endl;
    }
    return 0;
}