#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650

#define ll long long
const int mod = 1e9 + 7;

// Recursion
ll solve(int i, int j, bool isTrue, string &exp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
            return exp[i] == 'F';
    }
    ll ways = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        ll leftTrue = solve(i, k - 1, true, exp);
        ll leftFalse = solve(i, k - 1, false, exp);
        ll rightTrue = solve(k + 1, j, true, exp);
        ll rightFalse = solve(k + 1, j, false, exp);
        if (exp[k] == '&')
        {
            if (isTrue)
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            else
                ways = (ways + (rightTrue * leftFalse) % mod + (rightFalse * leftTrue) % mod + (rightFalse * leftFalse) % mod) % mod;
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
                ways = (ways + (rightTrue * leftFalse) % mod + (rightFalse * leftTrue) % mod + (rightTrue * leftTrue) % mod) % mod;
            else
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
        }
        else
        {
            if (isTrue)
                ways = (ways + (rightFalse * leftTrue) % mod + (rightTrue * leftFalse) % mod) % mod;
            else
                ways = (ways + (rightFalse * leftFalse) % mod + (rightTrue * leftTrue) % mod) % mod;
        }
    }
    return ways;
}
// Memoisation
ll solveMemo(int i, int j, bool isTrue, string &exp, vector<vector<vector<ll>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }
    ll ways = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        ll leftTrue = solveMemo(i, k - 1, true, exp, dp);
        ll leftFalse = solveMemo(i, k - 1, false, exp, dp);
        ll rightTrue = solveMemo(k + 1, j, true, exp, dp);
        ll rightFalse = solveMemo(k + 1, j, false, exp, dp);
        if (exp[k] == '&')
        {
            if (isTrue)
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            else
                ways = (ways + (rightTrue * leftFalse) % mod + (rightFalse * leftTrue) % mod + (rightFalse * leftFalse) % mod) % mod;
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
                ways = (ways + (rightTrue * leftFalse) % mod + (rightFalse * leftTrue) % mod + (rightTrue * leftTrue) % mod) % mod;
            else
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
        }
        else
        {
            if (isTrue)
                ways = (ways + (rightFalse * leftTrue) % mod + (rightTrue * leftFalse) % mod) % mod;
            else
                ways = (ways + (rightFalse * leftFalse) % mod + (rightTrue * leftTrue) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string &exp)
{

    // Recursive Call
    //    solve(0,exp.length()-1,1,exp);

    // Top Down Call
    int n = exp.length();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return solveMemo(0, n - 1, 1, exp, dp);
}