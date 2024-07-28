#include <bits/stdc++.h>
using namespace std;

/*
A. Maximize the Last Element
time limit per test1 second
memory limit per test256 megabytes
You are given an array a of n integers, where n is odd.

In one operation, you will remove two adjacent elements from the array a, and then concatenate the remaining parts of the array. For example, given the array [4,7,4,2,9]
, we can obtain the arrays [4,2,9] and [4,7,9] by the operations [4,7––––,4,2,9]→[4,2,9] and [4,7,4,2––––,9]→[4,7,9] respectively. However, we cannot obtain the array [7,2,9]
 as it requires deleting non-adjacent elements [4–,7,4–,2,9].

You will repeatedly perform this operation until exactly one element remains in a.

Find the maximum possible value of the remaining element in a.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. The description of test cases follows.
The first line of each test case contains a single integer n (1≤n≤99; n is odd) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤100) — the elements of the array a.

Note that there is no bound on the sum of n over all test cases.

Output
For each test case, output a single integer — the maximum possible value of the remaining element in a.
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
        vi arr(n);
        take(arr);

        if (n == 1)
        {
            cout << arr[0] << endl;
            continue;
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i += 2)
        {
            ans = max(ans, arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}