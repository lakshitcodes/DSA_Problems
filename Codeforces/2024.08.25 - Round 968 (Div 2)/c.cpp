#include <bits/stdc++.h>
using namespace std;

/*
C. Turtle and Good Pairs
time limit per test2 seconds
memory limit per test256 megabytes
Turtle gives you a string s, consisting of lowercase Latin letters.

Turtle considers a pair of integers (i,j) (1≤i<j≤n) to be a pleasant pair if and only if there exists an integer k such that i≤k<j and both of the following two conditions hold:

sk≠sk+1;sk≠si or sk+1≠sj.
Besides, Turtle considers a pair of integers (i,j) (1≤i<j≤n) to be a good pair if and only if si=sj or (i,j) is a pleasant pair.

Turtle wants to reorder the string s so that the number of good pairs is maximized. Please help him!

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains a single integer n (2≤n≤2⋅105) — the length of the string.

The second line of each test case contains a string s of length n, consisting of lowercase Latin letters.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output the string s after reordering so that the number of good pairs is maximized. If there are multiple answers, print any of them.
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
        string s;
        cin >> s;
        vi count(26, 0);
        for (auto &i : s)
        {
            count[i - 'a']++;
        }
        priority_queue<pair<int, char>> q;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {

                q.push({count[i], 'a' + i});
            }
        }
        queue<pair<char, int>> pq;
        while (!q.empty())
        {
            pq.push({q.top().second, q.top().first});
            q.pop();
        }
        string ans = "";
        while (!pq.empty())
        {
            char ch = pq.front().first;
            int freq = pq.front().second;
            pq.pop();
            ans += ch;
            if (freq > 1)
            {
                pq.push({ch, freq - 1});
            }
        }
        cout << ans << endl;
    }
    return 0;
}