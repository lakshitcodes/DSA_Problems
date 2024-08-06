#include <bits/stdc++.h>
using namespace std;

/*
C. Showering
time limit per test2 seconds
memory limit per test256 megabytes
As a computer science student, Alex faces a hard challenge — showering. He tries to shower daily, but despite his best efforts there are always challenges. He takes s minutes to shower and a day only has m minutes!

He already has n tasks planned for the day. Task i is represented as an interval (li, ri), which means that Alex is busy and can not take a shower in that time interval (at any point in time strictly between li and ri). No two tasks overlap.

Given all n time intervals, will Alex be able to shower that day? In other words, will Alex have a free time interval of length at least s?


In the first test case, Alex can shower for the first 3 minutes of the day and not miss any of the tasks.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.
The first line of each test case contains three integers n, s, and m (1≤n≤2⋅105; 1≤s,m≤109) — the number of time intervals Alex already has planned, the amount of time Alex takes to take a shower, and the amount of minutes a day has.

Then n lines follow, the i-th of which contains two integers li and ri (0≤li<ri≤m) — the time interval of the i-th task. No two tasks overlap.
Additional constraint on the input: li>ri−1 for every i>1.

The sum of n over all test cases does not exceed 2⋅105.

Output
For each test case output "YES" (without quotes) if Alex can take a shower for that given test case, and "NO" (also without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).
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
        int n, s, m;
        cin >> n >> s >> m;
        vii arr(n);
        for (auto &i : arr)
        {
            cin >> i.first >> i.second;
        }
        sort(arr.begin(), arr.end());
        bool found = false;
        if (arr[0].first >= s)
        {
            found = true;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1].first - arr[i].second >= s)
            {
                found = true;
                break;
            }
        }
        if (m - arr[n - 1].second >= s)
        {
            found = true;
        }
        if (found)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}