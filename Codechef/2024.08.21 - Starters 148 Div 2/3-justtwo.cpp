#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.codechef.com/START148B/problems/JUSTTWO

#define ll long long
#define vi vector<int>
#define vll vector<long long>

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for (auto &i : arr)
            cin >> i;

        priority_queue<ll, vll, greater<ll>> pq;
        for (auto &i : arr)
        {
            pq.push(i);
        }
        bool bigger = false;
        int count = 0;
        if (k > n)
        {
            count = k / n;
            k %= n;
            bigger = true;
        }

        while (k--)
        {
            ll element = pq.top();
            pq.pop();
            element *= 2;
            pq.push(element);
        }

        ll ans = 0;
        while (!pq.empty())
        {
            ans = (ans + pq.top()) % mod;
            pq.pop();
        }
        if (bigger)
        {

            ll multiplier = (1LL << count) % mod;
            ans = (ans * multiplier) % mod;
        }

        cout << ans << endl;
    }

    return 0;
}