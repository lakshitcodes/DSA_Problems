#include <bits/stdc++.h>
using namespace std;

/*
A. Legs
time limit per test2 seconds
memory limit per test256 megabytes
It's another beautiful day on Farmer John's farm.

After Farmer John arrived at his farm, he counted n legs. It is known only chickens and cows live on the farm, and a chicken has 2 legs while a cow has 4

What is the minimum number of animals Farmer John can have on his farm assuming he counted the legs of all animals?

Input
The first line contains single integer t (1≤t≤103) — the number of test cases.

Each test case contains an integer n (2≤n≤2⋅103, n is even).

Output
For each test case, output an integer, the minimum number of animals Farmer John can have on his farm.
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
        int ans = 0;
        ans += n / 4;
        n %= 4;
        ans += n / 2;
        cout << ans << endl;
    }
    return 0;
}