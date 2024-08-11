#include <bits/stdc++.h>
using namespace std;

/*
A. Distanced Coloring
time limit per test1 second
memory limit per test256 megabytes
You received an n×m grid from a mysterious source. The source also gave you a magic positive integer constant k.

The source told you to color the grid with some colors, satisfying the following condition:

If (x1,y1), (x2,y2) are two distinct cells with the same color, then max(|x1−x2|,|y1−y2|)≥k.
You don't like using too many colors. Please find the minimum number of colors needed to color the grid.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). The description of the test cases follows.

The only line of each test case consists of three positive integers n, m, k (1≤n,m,k≤104) — the dimensions of the grid and the magic constant.

Output
For each test case, print a single integer — the minimum number of colors needed to color the grid.
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
        int n, m, k;
        cin >> n >> m >> k;

        int a = min(n, k);
        int b = min(m, k);
        cout << a * b << endl;
    }
    return 0;
}