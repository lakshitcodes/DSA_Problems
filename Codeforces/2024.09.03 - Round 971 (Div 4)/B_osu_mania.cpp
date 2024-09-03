#include <bits/stdc++.h>
using namespace std;

/*
B. osu!mania
time limit per test
1 second
memory limit per test
256 megabytes

You are playing your favorite rhythm game, osu!mania. The layout of your beatmap consists of n rows and 4

columns. Because notes at the bottom are closer, you will process the bottommost row first and the topmost row last. Each row will contain exactly one note, represented as a '#'.

For each note 1,2,…,n, in the order of processing, output the column in which the note appears.
Input
The first line contains t(1≤t≤100) — the number of test cases.

For each test case, the first line contains n(1≤n≤500) — the number of rows of the beatmap.

The following nlines contain 4 characters. The i-th line represents the i-th row of the beatmap from the top. It is guaranteed that the characters are either '.' or '#', and exactly one of the characters is '#'.

It is guaranteed that the sum of n over all test cases does not exceed 500.
Output
For each test case, output n integers on a new line, the column that the i-th note appears in for all i from 1 to n.
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
        vs arr(n);
        take(arr);
        vector<int> ans;
        for (auto &s : arr)
        {
            for (int i = 0; i < 4; i++)
            {
                if (s[i] == '#')
                {
                    ans.push_back(i + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}