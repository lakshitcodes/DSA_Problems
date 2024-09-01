#include <bits/stdc++.h>
using namespace std;

/*
D. Sakurako's Hobby
time limit per test2 seconds
memory limit per test256 megabytes
For a certain permutation p
∗
 Sakurako calls an integer j breachable from an integer i if it is possible to make i equal to j by assigning i=pi a certain number of times.

If p=[3,5,6,1,2,4], then, for example, 4 is reachable from 1, because: i=1 → i=p1=3 → i=p3=6 → i=p6=4. Now i=4, so 4 is reachable from 1.

Each number in the permutation is colored either black or white.

Sakurako defines the function F(i) as the number of black integers that are reachable from i.

Sakurako is interested in F(i) for each 1≤i≤n, but calculating all values becomes very difficult, so she asks you, as her good friend, to compute this.
∗
A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (the number 2 appears twice in the array), and [1,3,4] is also not a permutation (n=3, but the array contains 4).

Input
The first line contains a single integer t (1≤t≤104)  — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤2⋅105)  — the number of elements in the array.

The second line of each test case contains n integers p1,p2,…,pn (1≤pi≤n)  — the elements of the permutation.

The third line of each test case contains a string s of length n, consisting of '0' and '1'. If si=0, then the number pi is colored black; if si=1, then the number pi is colored white.

It is guaranteed that the sum of n across all test cases does not exceed 2⋅105.

Output
For each test case, output n integers F(1),F(2),…,F(n).
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
        vi p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        string s;
        cin >> s;
        vector<int> result(n, 0);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                vector<int> cycle;
                int current = i;
                while (!visited[current])
                {
                    visited[current] = true;
                    cycle.push_back(current);
                    current = p[current];
                }
                int blackCount = 0;
                for (int node : cycle)
                {
                    if (s[node] == '0')
                    {
                        blackCount++;
                    }
                }
                for (int node : cycle)
                {
                    result[node] = blackCount;
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}