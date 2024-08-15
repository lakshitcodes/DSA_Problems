#include <bits/stdc++.h>
using namespace std;

/*
C. Splitting Items
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob have n items they'd like to split between them, so they decided to play a game. All items have a cost, and the i-th item costs ai. Players move in turns starting from Alice.

In each turn, the player chooses one of the remaining items and takes it. The game goes on until no items are left.

Let's say that A is the total cost of items taken by Alice and B is the total cost of Bob's items. The resulting score of the game then will be equal to A−B.

Alice wants to maximize the score, while Bob wants to minimize it. Both Alice and Bob will play optimally.

But the game will take place tomorrow, so today Bob can modify the costs a little. He can increase the costs ai of several (possibly none or all) items by an integer value (possibly, by the same value or by different values for each item). However, the total increase must be less than or equal to k
. Otherwise, Alice may suspect something. Note that Bob can't decrease costs, only increase.

What is the minimum possible score Bob can achieve?

Input
The first line contains a single integer t (1≤t≤5000) — the number of test cases. Then t cases follow.

The first line of each test case contains two integers n and k (2≤n≤2⋅105; 0≤k≤109) — the number of items and the maximum total increase Bob can make.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the initial costs of the items.

It's guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

Output
For each test case, print a single integer — the minimum possible score A−B after Bob increases the costs of several (possibly none or all) items.
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
        int n, k;
        cin >> n >> k;
        vi arr(n);
        take(arr);
        sort(arr.rbegin(), arr.rend());
        for (int i = 1; i < n && k; i += 2)
        {
            int diff = arr[i - 1] - arr[i];
            if (diff <= k)
            {
                arr[i] = arr[i - 1];
                k -= diff;
            }
            else
            {
                arr[i] += k;
                k = 0;
            }
        }
        ll a = 0, b = 0;
        for (int i = 0; i < n; i += 2)
        {
            a += arr[i];
        }
        for (int i = 1; i < n; i += 2)
        {
            b += arr[i];
        }
        cout << a - b << endl;
    }
    return 0;
}