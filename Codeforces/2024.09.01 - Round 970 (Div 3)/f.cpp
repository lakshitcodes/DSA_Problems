#include <bits/stdc++.h>
using namespace std;

/*
F. Sakurako's Box
time limit per test
2 seconds
memory limit per test
256 megabytes

Sakurako has a box with nballs. Each ball has it's value. She wants to bet with her friend that if the friend randomly picks two balls from the box (it could be two distinct balls, but they may have the same value), the product of their values will be the same as the number that Sakurako guessed.

Since Sakurako has a PhD in probability, she knows that the best number to pick is the expected value, but she forgot how to calculate it. Help Sakurako and find the expected value of the product of two elements from the array.

It can be shown that the expected value has the form PQ, where P and Q are non-negative integers, and Q≠0. Report the value of P⋅Q−1(mod109+7)
.
Input

The first line contains a single integer t(1≤t≤104)  — the number of test cases.

The first line of each test case contains a single integer n(2≤n≤2⋅105)  — the number of elements in the array.

The second line of each test case contains nintegers a1,a2,…,an (0≤ai≤109)  — the elements of the array.

It is guaranteed that the sum of nacross all test cases does not exceed 2⋅105.
Output

For each test case, output the value of P⋅Q−1(mod109+7).
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
const ll mod = 1e9 + 7;

ll fastmul(ll a, ll b)
{
    return (a * b) % mod;
}
ll fastadd(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}
ll binpow(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll res = binpow(x, y / 2);
    res = fastmul(res, res);
    if (y % 2)
    {
        return fastmul(res, x);
    }
    return res;
}
ll modinv(ll x, ll y = mod)
{
    return binpow(x, y - 2);
}

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
        vll arr(n);
        take(arr);
        ll sum = accumulate(arr.begin(), arr.end(), 0);
        ll sol = 0;
        for (int i = 0; i < n; i++)
        {
            sol = fastadd(sol, fastmul(sum - arr[i], arr[i]));
        }
        cout << fastmul(sol, modinv(fastmul(n, n - 1))) << endl;
    }
    return 0;
}