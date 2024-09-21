#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vb vector<bool>
#define vll vector<long long>
#define m(a, b) map<a, b>
#define set(a, b) set<a, b>
#define sort(arr) sort(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
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
        ll n;
        cin >> n;
        vll arr(n);
        take(arr);
        sort(arr);
        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (n <= 2)
        {
            cout << -1 << endl;
            continue;
        }
        ll total = sum(arr);
        ll average = arr[n / 2] * n;
        ll requiredAverage = average * 2 + 1;
        cout << max(requiredAverage - total, 0LL) << endl;
    }
    return 0;
}